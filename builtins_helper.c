/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:25:58 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:12 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

/* 
delete_last: Nuke the last string of array into orbit. 
move_back: send the position argument to end of the array.
		   return movement steps in array
*/

void	delete_last(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		i++;
	}
	free (args[i]);
	free(args[i - 1]);
	args[i - 1] = NULL;
}

int	move_back(char **args, int position)
{
	int		p;
	char	*temp;

	p = position;
	while (args[position + 1])
	{
		temp = args[position + 1];
		args[position + 1] = args[position];
		args[position] = temp;
		position++;
	}
	return (position - p);
}

void	ft_put(t_parameters *params, char **args, int i)
{
	if (args[i + 1])
	{
		ft_putstr_fd(args[i], params->fd_io[1]);
		ft_putstr_fd(" ", params->fd_io[1]);
	}
	else
		ft_putstr_fd(args[i], params->fd_io[1]);
}

int	n_checker(char *s)
{
	int		i;
	size_t	counter;

	i = 1;
	counter = 1;
	if (s[0] == '-')
	{
		while (s[i])
		{
			if (s[i] == 'n')
				counter++;
			i++;
		}
		if (counter == ft_strlen(s))
			return (1);
	}
	return (0);
}
