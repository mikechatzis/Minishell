/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/18 19:30:42 by mchatzip         ###   ########.fr       */
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
	free(ENV[1]);
	ENV[1] = ft_strjoin("PWD=", tmp);
	free(tmp);
}

void	execprog(char *b)
{
	char	**rpaths;
	char	**argvs;
	char	*tmp;
	char	*fpath;
	int		i;

	ENV[0] += 5;
	rpaths = ft_split(ENV[0], ':');
	argvs = ft_split(b, ' ');
	tmp = ft_strjoin(*rpaths, "/");
	fpath = ft_strjoin(tmp, &argvs[0][2]);
	free(tmp);
	if ((i = execve(&b[2], argvs, ENV)) == -1)
	{
		while ((i = (execve(fpath, argvs, ENV))) == -1 && *rpaths)
		{
			free(fpath);
			rpaths++;
			if (i == -1)
				perror(&b[2]);
			tmp = ft_strjoin(*rpaths, "/");
			fpath = ft_strjoin(tmp, &argvs[0][2]);
			free(tmp);
		}
	}
	free3(rpaths, argvs, fpath);
}

void	exececho(char *b)
{
	if (echoerrcheck(b))
		return ;
	if (ft_strnstr(b, "-n", 7))
		b += 7;
	else
		b += 5;
	while (*b == ' ' && *b)
		b++;
	while (*b)
	{
		if (*b == ' ')
			b = handlespace(b);
		if (*b == '\'')
			b = handlesquotes(b);
		if (*b == '"')
			b = handledquotes(b);
		if (*b == '$')
			b = printvar(b);
		// if (!strncmp(b, "$$", 2))
		// 	b = handlepiddis(b);
		if (*b != ' ' && *b != '$' && *b != '\'' && *b != '"')
		{
			printf("%c", *b);	
			b++;
		}
	}
	if (ft_strnstr(b, "-n", 7))
		printf("%%\n");
	else
		printf("\n");
}
