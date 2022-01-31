/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/31 15:47:53 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execseqcmd(char **rpaths, char **argvs, char *fpath)
{
	int		i;
	bool	c;
	char	*tmp;

	c = false;
	i = execve(argvs[0], argvs, g_env);
	if (i == -1)
	{
		while (i == -1 && *rpaths)
		{
			i = execve(fpath, argvs, g_env);
			rpaths++;
			if (!*rpaths)
				c = true;
			if (i == -1 && c == true)
				printf("minishell: command not found: %s\n", argvs[0]);
			free(fpath);
			tmp = ft_strjoin(*rpaths, "/");
			fpath = ft_strjoin(tmp, argvs[0]);
			free(tmp);
		}	
	}
}
