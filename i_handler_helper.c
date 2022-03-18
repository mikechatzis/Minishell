/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_handler_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:38:34 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:43:51 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

/*
handle_i();			Handle multiple, position-independent input redirection.
handle_i_join();	Handle multiple, position-independent input redirection 
					with joined markers.
handle_i2();		Handle multiple, position-independent here documents. 
handle_i2_join();	Handle multiple, position-independent here documents 
					with joined markers.
access_i_file();	check if input file is accessible
*/

int	handle_i(t_parameters *params, char **args, int *i)
{
	if (!ft_strcmp(args[*i], "<") && args[*i + 1])
	{
		if (params->i_file > 0 && params->i_file--)
			delete_last(args);
		move_back (args, *i + 1);
		move_back (args, *i);
		params->i_file++;
		*i = 0;
	}
	return (0);
}

int	handle_i_join(t_parameters *params, char **args, int *i)
{
	int		mv;
	char	*temp;

	if (args[*i][0] == '<' && args[*i][1] != '<')
	{
		if (params->i_file > 0 && params->i_file--)
			delete_last(args);
		mv = move_back(args, *i);
		temp = ft_strdup(&args[*i + mv][1]);
		free (args[*i + mv]);
		args[*i + mv] = temp;
		params->i_file++;
		*i = 0;
		return (1);
	}
	return (0);
}

int	handle_i2(t_parameters *params, char **args, int *i)
{
	int	mv;

	if (!ft_strcmp(args[*i], "<<") && args[*i + 1])
	{
		if (params->i_file > 0 && params->i_file--)
			delete_last(args);
		mv = move_back(args, *i + 1);
		move_back(args, *i);
		delete_last(args);
		writer_handle(args[*i + mv], params);
		delete_last(args);
		args[*i + mv] = ft_strdup("_tmp");
		params->i_file++;
		*i = 0;
		return (1);
	}
	return (0);
}

int	handle_i2_join(t_parameters *params, char **args, int *i)
{
	int		mv;
	char	*temp;

	if (args[*i][0] == '<' && args[*i][1] == '<' && args[*i][2])
	{
		if (params->i_file > 0 && params->i_file--)
			delete_last(args);
		mv = move_back(args, *i);
		temp = ft_strdup(&args[*i + mv][2]);
		free(args[*i + mv]);
		args[*i + mv] = temp;
		writer_handle(args[*i + mv], params);
		delete_last(args);
		args[*i + mv] = ft_strdup("_tmp");
		params->i_file++;
		*i = 0;
		return (1);
	}
	return (0);
}

void	access_i_file(t_parameters *params, char **args)
{
	int	i;

	if (params->i_file > 0)
	{
		i = 0;
		while (args[i])
			i++;
		if (i == 1)
		{
			ft_putstr_fd("usage: < input_file command\n", STDERR_FILENO);
			exit (EXIT_FAILURE);
		}
		else if (access (args[i - 1], F_OK) != 0
			|| access (args[i - 1], R_OK) != 0)
		{
			ft_putstr_fd (args[i - 1], STDERR_FILENO);
			perror (" cannot be accessed");
		}
	}
}
