/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:51:14 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/11 18:13:03 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_pipex
{
	int		p[2];
	int		pid;
	int		fd1;
	int		fd2;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*cmd_path1;
	char	*cmd_path2;
}	t_pipex;

void	ft_perror(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strncmp(const char	*s1, const char *s2, int n);
char	*ft_check_acs(char **env, char *cmd);

#endif