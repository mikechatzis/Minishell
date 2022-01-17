/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/17 13:39:23 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(char *b)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		execprog(b);
	wait(&pid);
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
		if (signum == SIGINT)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
}

int	sighandler(void)
{
	struct sigaction	s;
	int					i;

	i = 1;
	s.sa_handler = dhandler;
	s.sa_flags = SA_RESTART;
	i = sigaction(SIGINT, &s, NULL);
	s.sa_handler = SIG_IGN;
	i = sigaction(SIGQUIT, &s, NULL);
	return (i);
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
