/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:37:02 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/03/06 11:12:30 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parrent_work(t_pipex *pipex, char **av, char **envp)
{
	pipex->fd2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	wait(NULL);
	if (pipex->fd2 == -1)
		ft_perror("outfile error :");
	pipex->cmd2_args = ft_split(av[3], ' ');
	pipex->cmd_path2 = ft_check_acs(envp, pipex->cmd2_args[0]);
	close(pipex->p[1]);
	if (dup2(pipex->fd2, 1) == -1)
		ft_perror("Parent first dup2 error");
	if (dup2(pipex->p[0], 0) == -1)
		ft_perror("Parent second dup2 error");
	close(pipex->fd2);
	close(pipex->p[0]);
	if (execve(pipex->cmd_path2, pipex->cmd2_args, envp) == -1)
		ft_perror("Parent execute failed !!");
}

void	child_work(t_pipex *pipex, char **av, char **envp)
{
	pipex->fd1 = open(av[1], O_RDONLY);
	if (pipex->fd1 == -1)
		ft_perror("infile error doesnot found :");
	pipex->cmd1_args = ft_split(av[2], ' ');
	pipex->cmd_path1 = ft_check_acs(envp, pipex->cmd1_args[0]);
	close(pipex->p[0]);
	if (dup2(pipex->fd1, 0) == -1)
		ft_perror("child first dup2 error");
	if (dup2(pipex->p[1], 1) == -1)
		ft_perror("child second dup2 error");
	close(pipex->p[1]);
	close(pipex->fd1);
	if (execve(pipex->cmd_path1, pipex->cmd1_args, envp) == -1)
		ft_perror("child execut failed");
}

int	main(int ac, char **av, char **envp)
{
	int		pid1;
	int		pid2;
	t_pipex	pop;

	if (ac != 5)
	{
		ft_perror("pipex: usage: ./pipex file1 \"cmd1\" \"cmd2\" file2");
	}
	pipe(pop.p);
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("forking failed");
	if (pid1 == 0)
		child_work(&pop, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		parrent_work(&pop, av, envp);
	close(pop.p[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
