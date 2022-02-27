/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/24 14:31:18 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execexit(char *b, char *buff, char *name, t_nums *n)
{
	char	**args;
	bool	num;

	args = ft_split(buff, ' ');
	if (!args[1])
		freedstring(args);
	if (!args[1])
		exit(0);
	if (args[2])
	{
		write(2, "exit: too many arguments\n", 25);
		freedstring(args);
		return ;
	}
	num = checkifnumeric(args[1]);
	if (num == 1 || ft_atoi(args[1]) < 0 || ft_atoi(args[1]) > 255)
	{
		printf
		("exit: argument: '%s' is not numeric or exceeds scope\n", args[1]);
		exitall(b, buff, name, n);
		freedstring(args);
		exit(255);
	}
	exit (freedstring(args));
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
	int		i;
	int		j;

	tmp = malloc(100);
	i = -1;
	j = -1;
	b = format(b);
	if (!*b)
		chdir(ft_strjoin("/Users/", exportout("$USER")));
	else if (chdir(b))
		perror(b);
	tmp = getcwd(tmp, 100);
	while (ft_strncmp(g_env[++i], "OLDPWD", 6))
		continue ;
	while (ft_strncmp(g_env[++j], "PWD", 3))
		continue ;
	free(g_env[i]);
	g_env[i] = ft_strjoin("OLD", g_env[j]);
	free(g_env[j]);
	g_env[j] = ft_strjoin("PWD=", tmp);
	free(tmp);
}

void	execprog(char *b)
{
	char	**rpaths;
	char	**argvs;
	char	*tmp;
	char	*fpath;
	int		i;

	i = -1;
	while (ft_strncmp(g_env[++i], "PATH", 4))
		continue ;
	while (*b == ' ')
		b++;
	g_env[i] += 5;
	rpaths = ft_split(g_env[i], ':');
	argvs = xportsplit(b);
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
	printf("%s", b);
	if (!i)
		printf("\n");
}
