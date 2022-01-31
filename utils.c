/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/31 15:48:10 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(char *b)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		execprog(b);
	else
		wait(&pid);
	if (g_env[998])
		free(g_env[998]);
	g_env[998] = ft_itoa(WEXITSTATUS(pid));
}

void	dhandler(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\b\b  ", 4);
		write(2, "\nMike's minishell % ", 20);
		rl_on_new_line();
	}
	else if (signum == SIGQUIT)
		return ;
}

int	countchar(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

void	execcmd(char *b)
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
	fpath = ft_strjoin(tmp, argvs[0]);
	free(tmp);
	execseqcmd(rpaths, argvs, fpath);
	free3(rpaths, argvs, fpath);
}

void	execcommand(char *b)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		execcmd(b);
	else
		wait(&pid);
	if (g_env[998])
		free(g_env[998]);
	g_env[998] = ft_itoa(WEXITSTATUS(pid));
}
