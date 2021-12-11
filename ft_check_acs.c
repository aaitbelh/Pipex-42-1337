/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_acs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:23:51 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/11 18:02:34 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", ft_strlen("PATH=")))
			break ;
		i++;
	}
	return (i);
}

char	*ft_check_acs(char **env, char *cmd)
{
	char	**string;
	char	*check;
	int		j;

	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			ft_perror("Permission denied error!!");
	}
	cmd = ft_strjoin("/", cmd);
	j = find_path(env);
	string = ft_split(env[j] + 5, ':');
	j = 0;
	while (string[j])
	{
		check = ft_strjoin(string[j], cmd);
		if (!access(check, X_OK))
			return (check);
		j++;
	}
	if (access(cmd, F_OK != 0))
		ft_perror("cmd not found");
	return (NULL);
}
