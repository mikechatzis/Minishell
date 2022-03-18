/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:01:10 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:43:39 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	handler(int signum, siginfo_t *info, void *unused)
{
	(void)unused;
	(void)info;
	if (signum == SIGINT)
	{
		printf("\b\b  \n");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		printf("\b\b  \b\b");
	}
}

void	signals(void)
{
	struct sigaction	sa_sig;

	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = handler;
	sigemptyset(&sa_sig.sa_mask);
	if (sigaction(SIGINT, &sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
	if (sigaction(SIGQUIT, &sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
}

void	initialization_pipe(t_parameters *params)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (params->command[i])
	{
		if (ft_strncmp(params->command[i], "|", 2) == 0)
			n++;
		i++;
	}
	params->n_pipe = n;
	i = 0;
	if (params->n_pipe > 0)
	{
		params->fd_pipe = ft_calloc(2 * params->n_pipe, sizeof(int));
		while (i < params->n_pipe)
		{
			if (pipe(params->fd_pipe + i * 2) < 0)
				pipe_failed(params);
			i++;
		}
	}
}

void	initialization(t_parameters *params)
{
	signals();
	params->i = 0;
	params->q = 0;
	params->qq = 0;
	params->pid = -42;
	params->i_file = 0;
	params->o_file = 0;
	params->flag_sq = 0;
	params->flag_dq = 0;
	params->o2_file = 0;
	params->i2_file = 0;
	params->path = NULL;
	params->fork_flag = 0;
	params->input_flag = 0;
	params->command = NULL;
	params->keep_stdout = 0;
	params->builtin_flag = 0;
	params->pipe_command = NULL;
	params->fd_io[0] = STDIN_FILENO;
	params->fd_io[1] = STDOUT_FILENO;
}
