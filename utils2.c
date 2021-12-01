/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/12/01 18:40:23 by mchatzip         ###   ########.fr       */
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
					write(2, "quote>\n", 7);
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
					write(2, "dquote>\n", 8);
					return (-1);
				}
			}
		}
	}
	return (0);
}

int	prints(char *s)
{
	int		i;
	int		j;
	char	*b[100];

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i])
				i++;
			b[j] = ft_substr(s, 1, i - 1);
			s += i + 1;
			i = 0;
			printf("%s", b[j++]);
		}
		else if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
			b[j] = ft_substr(s, 1, i - 1);
			s += i + 1;
			i = 0;
			printf("%s", b[j++]);
		}
		else
		{
			while (s[i] != '"' && s[i] != '\'' && s[i])
				i++;
			b[j] = ft_substr(s, 0, i);
			s += i;
			i = 0;
			printf("%s", b[j++]);
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
		if (!ft_strncmp(b[i], name, len))
		{
			free(s);
			s = ft_substr(b[i], len + 1, ft_strlen(b[i]));
			return (s);
		}
	}
	return (s);
}

int	printvar(char *s)
{
	char	*b;
	
	b = parseenv(ENV, &s[1]);
	printf("%s", b);
	free(b);
	return 0;
}
