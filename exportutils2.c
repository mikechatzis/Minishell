/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/31 16:28:14 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handlepiddisxp(char *b, char *ret)
{
	b += 2;
	ft_strncat(ret, ft_itoa(getpid()), 5);
	return (b);
}

char	*emptynamexp(char *s, char *ret)
{
	if (s[1] == '$')
	{
		handlepiddisxp(s, ret);
		s += 2;
	}
	else if (!s[1] || s[1] == ' ' || s[1] == '"' || s[1] == '\'')
	{
		ft_strncat(ret, "$", 1);
		s += 1;
	}
	return (s);
}

char	*zeroorhashxp(char *s, char *ret)
{
	if (s[1] == '0')
	{
		ft_strncat(ret, "minishell", 9);
		s += 2;
	}
	else if (s[1] == '#')
	{
		ft_strncat(ret, "0", 1);
		s += 2;
	}
	else if (s[1] == '?')
	{
		ft_strncat(ret, g_env[998], ft_strlen(g_env[998]));
		s += 2;
	}
	return (s);
}

char	*allelsexp(char *b, char *s, char *name, char *ret)
{
	ft_strncat(ret, b, ft_strlen(b));
	s += ft_strlen(name) + 1;
	free(b);
	return (s);
}

char	*printvarxp(char *s, char *ret)
{
	char	*b;
	char	*name;
	int		i;

	while (*s)
	{
		i = 1;
		while (s[i] && s[i] != ' '
			&& s[i] != '$' && s[i] != '"' && s[i] != '\'')
			i++;
		name = ft_substr(&s[1], 0, i - 1);
		if (!*name)
			s = emptynamexp(s, ret);
		else if (s[1] == '0' || s[1] == '#' || s[1] == '?')
			s = zeroorhashxp(s, ret);
		else
		{
			b = parseenv(g_env, name);
			s = allelsexp(b, s, name, ret);
		}
		free(name);
		if (*s != '$')
			break ;
	}
	return (s);
}
