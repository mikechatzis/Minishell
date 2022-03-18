/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:37:10 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:24 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

static int	is_sq(t_parameters *params, int *i)
{
	if (params->line[*i] == '\'')
	{
		if (params->flag_sq == 0)
			params->flag_sq = 1;
		else
			params->flag_sq = 0;
		*i = *i + 1;
		return (1);
	}
	return (0);
}

static int	is_dq(t_parameters *params, int *i)
{
	if (params->line[*i] == '\"')
	{
		if (params->flag_dq == 0)
			params->flag_dq = 1;
		else
			params->flag_dq = 0;
		*i = *i + 1;
		return (1);
	}
	return (0);
}

static int	remove_comments(t_parameters *params, int *i)
{
	char	*tmp;

	params->line[*i] = '\0';
	tmp = ft_strdup(params->line);
	free(params->line);
	params->line = tmp;
	return (1);
}

static void	handle_comments_core(t_parameters *params)
{
	int		i;

	i = 0;
	while (params->line[i])
	{
		if (is_sq(params, &i))
			continue ;
		if (is_dq(params, &i))
			continue ;
		if (params->line[i] == ' ')
		{
			if (params->line[i + 1])
			{
				if (params->line[i + 1] == '#' && params->flag_sq == 0
					&& params->flag_dq == 0 && remove_comments(params, &i))
					return ;
			}
			else
				return ;
		}
		i++;
	}
}

void	do_comments(t_parameters *params)
{
	if (!ft_strncmp(params->line, "#", 1))
	{
		free(params->line);
		params->line = "";
		return ;
	}
	handle_comments_core(params);
}
