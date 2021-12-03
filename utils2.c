/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/12/03 16:48:01 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echoerrcheck(char *b)
{
	int	i;

	i = -1;
	while (b[++i])
	{
		if (b[i] == '\'')
		{
			while (b[++i] != '\'')
			{
				if (!b[i])
				{
					write(2, "missing quote>\n", 15);
					return (-1);
				}
			}
		}
		if (b[i] == '"')
		{
			while (b[++i] != '"')
			{
				if (!b[i])
				{
					write(2, "missing dquote>\n", 16);
					return (-1);
				}
			}
		}
	}
	return (0);
}

int	prints(char *s, t_nums *n)
{
	int		i;
	int		j;
	char	*b;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i])
				i++;
			b = ft_substr(s, 1, i - 1);
			s += i + 1;
			i = 0;
			n->print = printf("%s", b);
			free(b);
		}
		else if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
			b = ft_substr(s, 1, i - 1);
			s += i + 1;
			i = 0;
			n->print = printf("%s", b);
			free(b);
		}
		else
		{
			while (s[i] != '"' && s[i] != '\'' && s[i] && s[i] != '$')
				i++;
			b = ft_substr(s, 0, i);
			s += i;
			i = 0;
			n->print = printf("%s", b);
			free(b);
			if (s[i] == '$')
				s += printvar(s, n);
		}
	}
	return (0);
}

int	namecmp(char *s, char *b)
{
	while(*s && *b)
	{
		if (*s != *b)
			break ;
		if (*s == '=' && *b == '=')
			return (1);
		s++;
		b++;
	}
	return (0);
}

char	*parseenv(char **b, char *name)
{
	char	*s;
	int		len;
	int		i;

	i = -1;
	s = ft_strdup("");
	len = ft_strlen(name);
	while (b[++i])
	{
		if (!ft_strncmp(b[i], name, len) && *name)
		{
			free(s);
			s = ft_substr(b[i], len + 1, ft_strlen(b[i]));
			return (s);
		}
	}
	return (s);
}

int	printvar(char *s, t_nums *n)
{
	char	*b;
	char	*name;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (s[i] && s[i] != '$')
		i++;
	if (!s[i + 1])
		i++;
	b = ft_substr(s, 0, i);
	n->print = printf("%s", b);
	s += i;
	free(b);
	i = 1;
	while (*s)
	{
		while (s[i] && s[i] != '\'' && s[i] != '"' && s[i] != '$')
			i++;
		name = ft_substr(&s[1], 0, i - 1);
		b = parseenv(ENV, name);
		n->print = printf("%s", b);
		ret += ft_strlen(name) + 1;
		free(b);
		free(name);
		s += i;
		if (*s != '$')
			break ;
	}
	return (ret);
}
