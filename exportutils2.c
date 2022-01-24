/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/24 17:13:37 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handlepiddisxp(char *b, int fd)
{
	b += 2;
	dprintf(fd, "%s", ft_itoa(getpid()));
	return (b);
}

char	*emptynamexp(char *s, int fd)
{
	if (s[1] == '$')
	{
		handlepiddisxp(s, fd);
		s += 2;
	}
	else if (!s[1] || s[1] == ' ' || s[1] == '"' || s[1] == '\'')
	{
		dprintf(fd, "$");
		s += 1;
	}
	return (s);
}

char	*zeroorhashxp(char *s, int fd)
{
	if (s[1] == '0')
	{
		dprintf(fd, "minishell");
		s += 2;
	}
	else if (s[1] == '#')
	{
		dprintf(fd, "0");
		s += 2;
	}
	return (s);
}

char	*allelsexp(char *b, char *s, char *name, int fd)
{
	dprintf(fd, "%s", b);
	s += ft_strlen(name) + 1;
	free(b);
	return (s);
}

char	*printvarxp(char *s, int fd)
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
			s = emptynamexp(s, fd);
		else if (s[1] == '0' || s[1] == '#')
			s = zeroorhashxp(s, fd);
		else
		{
			b = parseenv(g_env, name);
			s = allelsexp(b, s, name, fd);
		}
		free(name);
		if (*s != '$')
			break ;
	}
	return (s);
}
