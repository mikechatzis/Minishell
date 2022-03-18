/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:59:37 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 14:25:00 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

/*
	-route function is running drive for start program
		and at the end it closes the duplicated FD
	-with the drive we are starting to split our commands one by one
		argument function is handle spliting arguments 1st for space 2nd for pipe
	- Drive is running the process mainly. 
	- do_execution is take all commands trhoughtly 
*/

void	close_pipe(t_parameters *params)
{
	int	i;
	int	st;

	i = 0;
	st = 0;
	while (i < 2 * params->n_pipe)
	{
		close(params->fd_pipe[i]);
		i++;
	}
	i = 0;
	while (i < params->n_pipe + 1)
	{
		wait (&st);
		i++;
	}
	if (!params->builtin_flag)
		params->exit_status = WEXITSTATUS(st);
	if (params->fd_io[1] != STDOUT_FILENO)
		close (params->fd_io[1]);
	if (params->n_pipe > 0)
		free(params->fd_pipe);
}

void	do_execution(t_parameters *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (params->pipe_command[i])
	{
		if (!fork_handler(params, &i, &j))
			continue ;
		if (params->pid == 0)
		{
			pipe_handler(params, i, j);
			execute_handler(params, i);
		}
		else if (params->pid < 0)
			fork_failed(params);
		i++;
		j += 2;
	}
}

char	**arguments(char const *s, char c)
{
	size_t	i;
	size_t	len2;
	char	**s_arr;
	char	*s_arr2;

	s_arr = (char **)malloc(sizeof(char *) * (arguments_counter(s, c) + 1));
	if (!s_arr)
		return (s_arr);
	i = 0;
	s_arr2 = (char *)s;
	len2 = 0;
	while (i < arguments_counter(s, c))
	{
		next_argument(&s_arr2, &len2, c);
		s_arr[i] = (char *)malloc(sizeof(char) * (len2 + 1));
		if (!s_arr[i])
			return (NULL);
		ft_strlcpy(s_arr[i], s_arr2, len2 + 1);
		i++;
	}
	s_arr[i] = NULL;
	return (s_arr);
}

void	drive(t_parameters *params)
{
	params->command = arguments(params->line, ' ');
	if (!params->command || !params->command[0])
		perror("No command passed");
	params->pipe_command = arguments(params->line, '|');
	initialization_pipe(params);
	do_execution(params);
	close_pipe(params);
	unlink("_tmp");
	freesplit(params->pipe_command);
	freesplit(params->command);
}

void	route(t_parameters *params)
{
	drive(params);
	if (params->pid >= 0)
		waitpid(params->pid, NULL, 0);
	if (params->keep_stdout)
	{
		dup2 (params->keep_stdout, STDOUT_FILENO);
		close (params->keep_stdout);
	}
	free (params->line);
}
