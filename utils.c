/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/24 14:56:35 by mchatzip         ###   ########.fr       */
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
	if (signum == SIGQUIT)
		exit(0);
}

void	bslashhandler(void)
{
	struct sigaction	s;

	s.sa_handler = dhandler;
	sigaction(SIGQUIT, &s, NULL);
}
