/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/30 17:13:11 by mchatzip         ###   ########.fr       */
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
			while(b[++i] != '\'')
				if (!b[i])
				{
					write(2, "<quote\n", 7);
					return (-1);
				}
		}
		if (b[i] == '"')
		{
			while(b[++i] != '"')
				if (!b[i])
				{
					write(2, "<dquote\n", 8);
					return (-1);
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
	free(b);
	return (0);
}

char	*prints2(char *s)
{
	if (!ft_strchr(&s[1], '\''))
	{
		write(2, "quote>", 6);
		return (0);
	}
	s++;
	while (*s != '\'')
	{
		write(1, &*s, 1);
		s++;
	}
	return (s + 1);
}
