/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/21 14:47:29 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execls(char *b)
{
	DIR				*dir;
	struct dirent	*curdir;
	int				l;

	l = ft_strlen(b);
	if (!ft_strncmp(b, "ls", l))
	{
		dir = opendir(".");
		if (!dir)
			perror("opendir error");
		else
		{
			curdir = readdir(dir);
			while ((curdir))
			{
				printf("%s  ", curdir->d_name);
				curdir = readdir(dir);
			}
			printf("\n");
			free(curdir);
		}
		closedir(dir);
	}
}

void	execpwd(void)
{
	char	*dirp;

	dirp = malloc(1000);
	dirp = getcwd(dirp, 1000);
	if (!dirp)
	{
		perror("getcwd error");
		free(dirp);
	}
	else
	{
		printf("%s\n", dirp);
		free(dirp);
	}
}

void	execcd(char *b)
{
	char	*tmp;

	tmp = malloc(100);
	while (*b != ' ' && *b)
		b++;
	b++;
	if (chdir(b))
		perror(b);
	tmp = getcwd(tmp, 100);
	free(g_env[1]);
	g_env[1] = ft_strjoin("PWD=", tmp);
	free(tmp);
}

void	execprog(char *b)
{
	char	**rpaths;
	char	**argvs;
	char	*tmp;
	char	*fpath;

	g_env[0] += 5;
	rpaths = ft_split(g_env[0], ':');
	argvs = ft_split(b, ' ');
	tmp = ft_strjoin(*rpaths, "/");
	fpath = ft_strjoin(tmp, &argvs[0][2]);
	free(tmp);
	execseq(b, rpaths, argvs, fpath);
	free3(rpaths, argvs, fpath);
}

void	exececho(char *b)
{
	int	i;

	i = 0;
	if (echoerrcheck(b))
		return ;
	if (ft_strnstr(b, "-n", 8))
	{
		b += 5;
		b = handlenflag(b);
		i = 1;
	}	
	else
		b += 5;
	while (*b == ' ')
		b++;
	while (*b)
		b = handleschars(b);
	if (!i)
		printf("\n");
}
