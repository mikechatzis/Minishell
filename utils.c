/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/27 13:46:06 by mchatzip         ###   ########.fr       */
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

void	ukncommand(char *b)
{
	int		i;

	i = -1;
	if (!*b)
		return ;
	while (b[++i] != ' ' && b[i])
		write(2, &b[i], 1);
	write(2, ": command not found\n", 20);
}

void	dhandler(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\b\b  ", 4);
		write(2, "\nMike's minishell % ", 20);
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
