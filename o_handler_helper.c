/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_handler_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:04:02 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:44:11 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

/* 
	handle_o();			Handle multiple, position-independent, 
						truncating output redirection.
	handle_o_join();	Handle multiple, position-independ, 
						trunc output redir with joined markers
	handle_o2();		Handle multiple, position-independent, 
						appending output redirection.
 */

int	handle_o(t_parameters *params, char **args, int *i)
{
	int	mv;

	if (!ft_strcmp(args[*i], ">") && args[*i + 1])
	{
		if (params->o_file > 0 && params->o_file--)
			close(params->fd_io[1]);
		mv = move_back(args, *i + 1);
		move_back(args, *i);
		params->fd_io[1] = open(args[*i + mv],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		delete_last(args);
		delete_last(args);
		params->o_file++;
		*i = 0;
		return (1);
	}
	return (0);
}

int	handle_o_join(t_parameters *params, char **args, int *i)
{
	char	*temp;
	int		mv;

	if (args[*i][0] == '>' && args[*i][1] && args[*i][1] != '>')
	{
		if (params->o_file > 0 && params->o_file--)
			close(params->fd_io[1]);
		mv = move_back(args, *i);
		temp = ft_strdup(&args[*i + mv][1]);
		free(args[*i + mv]);
		args[*i + mv] = temp;
		params->fd_io[1] = open(args[*i + mv],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		delete_last(args);
		params->o_file++;
		*i = 0;
		return (1);
	}
	return (0);
}

int	handle_o2(t_parameters *params, char **args, int *i)
{
	int		mv;

	if (!ft_strcmp(args[*i], ">>") && args[*i + 1])
	{
		if (params->o_file > 0 && params->o_file--)
			close(params->fd_io[1]);
		mv = move_back(args, *i + 1);
		move_back(args, *i);
		params->fd_io[1] = open(args[*i + mv],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		delete_last(args);
		delete_last(args);
		params->o_file++;
		*i = 0;
		return (1);
	}
	return (0);
}

int	handle_o2_join(t_parameters *params, char **args, int *i)
{
	char	*temp;
	int		mv;

	if (args[*i][0] == '>' && args[*i][1] == '>' && args[*i][2])
	{
		if (params->o_file > 0 && params->o_file--)
			close(params->fd_io[1]);
		mv = move_back(args, *i);
		temp = ft_strdup(&args[*i + mv][2]);
		free(args[*i + mv]);
		args[*i + mv] = temp;
		params->fd_io[1] = open(args[*i + mv],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		delete_last(args);
		params->o_file++;
		*i = 0;
		return (1);
	}
	return (0);
}

void	command_redirection(t_parameters *params)
{
	if (params->fd_io[1] == -1)
		return (open_failed (params));
	if (params->fork_flag && dup2(params->fd_io[1], STDOUT_FILENO) == -1)
		return (dup_failed (params));
	else
	{
		params->keep_stdout = dup (STDOUT_FILENO);
		if (params->keep_stdout < 0
			|| dup2(params->fd_io[1], STDOUT_FILENO) == -1)
			return (dup_failed (params));
	}	
}
