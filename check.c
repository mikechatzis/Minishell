/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:41:14 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:19 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

char	*single_quot(t_parameters *params, char *s)
{
	int		i;
	char	**buf;
	char	*temp;

	i = 0;
	buf = ft_split(s, ' ');
	while (buf[i])
	{
		buf[i] = parse_v(params, buf[i]);
		i++;
	}
	s = qtoback(buf);
	temp = ft_strjoin("\"", s);
	free(s);
	s = ft_strjoin(temp, "\"");
	free(temp);
	freesplit(buf);
	return (s);
}

char	*exp_check(t_parameters *params, char *s)
{
	int		i;
	char	**buf;
	char	*temp;
	char	*s2;

	i = 0;
	buf = ft_split(s, ' ');
	while (buf[i])
	{
		if (buf[i][0] == '\'' && buf[i][ft_strlen(buf[i]) - 1] == '\'')
		{
			buf[i][ft_strlen(buf[i]) - 1] = '\0';
			buf[i] = parse_v(params, &buf[i][1]);
			temp = ft_strjoin("\'", buf[i]);
			buf[i] = ft_strjoin(temp, "\'");
			free(temp);
		}
		else
			buf[i] = parse_v(params, buf[i]);
		i++;
	}
	s2 = qqpasteback(buf);
	freesplit(buf);
	return (s2);
}

char	*parse_v(t_parameters *params, char *s)
{
	params->buf = newstring(0);
	while (s[params->i])
	{
		if (s[params->i] == '\'')
			q_handler(params, s);
		else if (s[params->i] == '\"')
			qq_handler(params, s);
		else if (s[params->i] == '$')
			jumper_v(params, s);
		else
			params->buf = addchar(params->buf, s[(params->i)++]);
	}
	params->i = 0;
	params->q = 0;
	params->qq = 0;
	free(s);
	return (params->buf);
}

char	*double_quot(t_parameters *params, char *s)
{
	char	*p;
	int		len;

	len = ft_strlen(s);
	if (s[0] == '\'' && s[ft_strlen(s) - 1] == '\'')
	{
		s[len - 1] = '\0';
		p = single_quot(params, &s[1]);
	}
	else
		p = exp_check(params, s);
	return (p);
}
