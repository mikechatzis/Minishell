/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:49:10 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:46 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	pipe_failed(t_parameters *params)
{
	perror("pipe() failed");
	free(params->fd_pipe);
	if (params->fork_flag)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	fork_failed(t_parameters *params)
{
	perror("fork() failed");
	if (params->fd_io[1] != STDOUT_FILENO)
		close(params->fd_io[1]);
	if (params->fork_flag)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	dup_failed(t_parameters *params)
{
	perror("dup2() failed");
	if (params->fork_flag)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	open_failed(t_parameters *params)
{
	perror("open() failed");
	if (params->fork_flag)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	write_failed(t_parameters *params, char *line)
{
	if (line == NULL)
		free(line);
	perror("write() failed");
	if (params->fork_flag)
		exit(EXIT_FAILURE);
	else
		return ;
}
