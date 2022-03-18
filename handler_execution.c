/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:26:08 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:43:27 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	pipe_handler(t_parameters *params, int i, int j)
{
	if (params->pipe_command[i + 1])
	{
		if (dup2(params->fd_pipe[j + 1], STDOUT_FILENO) < 0)
			return (dup_failed(params));
	}
	if (j != 0)
	{
		if (dup2(params->fd_pipe[j - 2], 0) < 0)
			return (dup_failed(params));
	}
	i = 0;
	while (i < 2 * params->n_pipe)
		close (params->fd_pipe[i++]);
}

int	fork_handler(t_parameters *params, int *i, int *j)
{
	char	**args;
	int		position;

	args = arguments(params->pipe_command[*i], ' ');
	env_handler(params, args);
	position = pass_executable(args);
	params->fork_flag = check_command(args[position], args[position + 1]);
	if (params->fork_flag)
		params->pid = fork();
	else
	{
		builtins_jumper(params, args);
		*i = *i + 1;
		*j = *j + 2;
		freesplit(args);
		return (0);
	}
	freesplit(args);
	return (1);
}

void	execute_handler(t_parameters *params, int i)
{
	char	**args;

	args = arguments(params->pipe_command[i], ' ');
	env_handler(params, args);
	i_handler(params, args);
	o_handler(params, args);
	if (ft_strchr(args[0], '/'))
	{
		if (execve(args[0], args, params->env) == -1)
			clean_exit(args);
	}
	else if (check_builtin(args[0]))
		builtins_jumper(params, args);
	else
	{
		if (is_null(params, args[0]))
			clean_exit(args);
		path_checker(params, args[0]);
		if (!params->path || execve(params->path, args, params->env) == -1)
			clean_exit(args);
	}
	freesplit(args);
}
