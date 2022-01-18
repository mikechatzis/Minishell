/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/18 19:52:27 by mchatzip         ###   ########.fr       */
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

char	*printvar(char *s)
{
	char	*b;
	char	*name;
	int		i;

	while (*s)
	{
		i = 1;
		while (s[i] && s[i] != ' ' && s[i] != '$')
			i++;
		name = ft_substr(&s[1], 0, i - 1);
		if (!*name)
		{
			if (s[1] == '$')
			{
				handlepiddis(s);	
				s += 2;
			}
			else if (!s[1] || s[1] == ' ' || s[1] == '"')
			{
				printf("$");
				s += 1;
			}
			
		}
		else if (s[1] == '0')
		{
			printf("minishell");	
			s += 2;
		}
		else
		{
			b = parseenv(ENV, name);
			printf("%s", b);
			s += ft_strlen(name) + 1;
			free(b);
		}
		free(name);
		if (*s != '$')
			break ;
	}
	return (s);
}
