/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/01 15:39:02 by mchatzip         ###   ########.fr       */
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

static char	*handlehyphen2(char *b, char *curuser, int i)
{
	if (curuser)
	{
		free(g_env[i]);
		g_env[i] = ft_strdup(curuser);
		free(curuser);
	}
	while (*b && *b != ' ')
		b++;
	return (b);
}

static void	handlehyphen3(char *b, char *tmp, char *ret)
{
	int		i;
	char	*buff;

	i = -1;
	if (!opendir(tmp))
	{
		while (b[++i] && b[i] != ' ')
			continue ;
		buff = ft_substr(b, 0, i);
		ft_strncat(ret, "~", 1);
		ft_strncat(ret, buff, ft_strlen(buff));
		free(buff);
	}
	else
		ft_strncat(ret, tmp, ft_strlen(tmp));
}

char	*handlehyphen(char *b, char *ret, t_nums *n)
{	
	char	*tmp;
	char	*curuser;
	int		i;
	size_t	j;

	i = -1;
	j = 0;
	b += 1;
	curuser = NULL;
	if (*b != ' ' && *b)
	{
		while (ft_strncmp(g_env[++i], "USER", 4))
			continue ;
		while (b[j] != ' ' && b[j])
			j++;
		curuser = ft_strdup(g_env[i]);
		execexport(ft_strjoin("export USER=", ft_substr(b, 0, j)), n);
	}
	tmp = ft_strjoin("/Users/", exportout("$USER", n));
	handlehyphen3(b, tmp, ret);
	b = handlehyphen2(b, curuser, i);
	free(tmp);
	return (b);
}
