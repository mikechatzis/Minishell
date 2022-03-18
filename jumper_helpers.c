/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumper_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:46:41 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:43:57 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

int	isspace(int ch)
{
	unsigned char	c;

	c = (unsigned char)(ch);
	if (c == ',' || c == '%' || c == '.' || c == '/' || c == ':' || c == '='
		|| c == '^' || c == ']' || c == '~' || c == '}')
		return (1);
	return (0);
}

static int	conditioner(t_parameters *params, char *s)
{
	char	*tmp2;
	char	*tmp1;

	if (s[params->i + 1] && (s[params->i + 1] == '?'
			|| s[params->i + 1] == '#'))
	{
		params->i = params->i + 2;
		tmp1 = params->buf;
		tmp2 = ft_itoa(params->exit_status);
		params->buf = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
		return (1);
	}
	if (s[params->i + 1] && (s[params->i + 1] == '$'))
	{
		params->i = params->i + 2;
		tmp1 = params->buf;
		tmp2 = ft_itoa(8596);
		params->buf = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
		return (1);
	}
	return (0);
}

int	single_par(t_parameters *params, char *s)
{
	if (conditioner(params, s))
		return (1);
	if (s[params->i + 1] && ft_isdigit(s[params->i + 1]))
	{
		params->i = params->i + 2;
		return (1);
	}
	if (!s[params->i + 1] || (s[params->i + 1] && isspace(s[params->i + 1]))
		|| ((s[params->i + 1] && !ft_isalnum(s[params->i + 1])) && params->qq))
	{
		params->buf = addchar(params->buf, s[(params->i)++]);
		return (1);
	}
	return (0);
}

int	is_var(t_parameters *params, char *s)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	i = params->i + 1;
	tmp = newstring(0);
	while ((s[i] && ft_isalnum(s[i])) || (s[i] && s[i] == '_'))
		tmp = addchar(tmp, s[i++]);
	if (!envget(params, tmp))
	{
		params->i = i;
		free(tmp);
		return (1);
	}
	else
	{
		params->i = i;
		tmp1 = params->buf;
		params->buf = ft_strjoin(tmp1, envget(params, tmp));
		free(tmp1);
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
