/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:35:33 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:44:14 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	jumper_v(t_parameters *params, char *s)
{
	if (single_par(params, s))
		return ;
	if (is_var(params, s))
		return ;
}

void	qq_handler(t_parameters *params, char *s)
{
	if (params->qq)
	{
		params->i++;
		params->qq = 0;
		return ;
	}
	else if (s[params->i + 1] && ft_strchr(&s[params->i + 1], '\"'))
	{
		params->i++;
		params->qq = 1;
		if (s[params->i] == '\"')
		{
			params->i++;
			params->qq = 0;
			return ;
		}
		return ;
	}
	params->buf = addchar(params->buf, s[(params->i)++]);
}

void	q_handler(t_parameters *params, char *s)
{
	if (params->q)
	{
		params->i++;
		params->q = 0;
		return ;
	}
	else if (s[params->i + 1] && ft_strchr(&s[params->i + 1], '\''))
	{
		params->i++;
		params->q = 1;
		if (s[params->i] == '\'')
		{
			params->i++;
			params->q = 0;
			return ;
		}
		while (s[params->i] != '\'')
			params->buf = addchar(params->buf, s[(params->i)++]);
		return ;
	}
	params->buf = addchar(params->buf, s[(params->i)++]);
}
