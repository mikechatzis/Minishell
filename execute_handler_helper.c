/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_handler_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:58:26 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:51 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

int	is_null(t_parameters *params, char *command)
{
	char	*temp;

	temp = envget(params, "PATH");
	if (!temp)
	{
		printf("minishell: %s: command not found\n", command);
		return (1);
	}
	return (0);
}

void	path_checker(t_parameters *params, char *command)
{
	struct stat	st;
	char		*c;
	char		*slash_string;
	char		**path_sp;
	int			i;

	path_sp = ft_split(envget(params, "PATH"), ':');
	i = 0;
	while (path_sp[i])
	{
		slash_string = ft_strjoin(path_sp[i++], "/");
		c = ft_strjoin(slash_string, command);
		free(slash_string);
		if (!stat(c, &st))
		{
			params->path = c;
			freesplit(path_sp);
			return ;
		}
		else
			free(c);
	}
	printf("minishell: %s: command not found\n", command);
	freesplit(path_sp);
}
