/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/05 21:01:36 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	incrementi(int i, char *s)
{
	char	*dest;

	dest = malloc(1000);
	while (g_env[i]
		&& (!namecmp(g_env[i], exportout2(dest, s)) || !g_env[i][0]))
		i++;
	free(dest);
	return (i);
}

static int	qqfoo(char *b, int i)
{
	if (b[i] == '\'')
	{
		while (b[++i] != '\'')
			continue ;
		i++;
	}
	if (b[i] == '"')
	{
		while (b[++i] != '"')
			continue ;
		i++;
	}
	return (i);
}

char	**xportsplit(char *b)
{
	char	**ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	ret = malloc(sizeof(char *) * sizeof(b));
	while (b[++i])
	{
		if (b[i] == '\'' || b[i] == '"')
			i = qqfoo(b, i);
		if (!b[i + 1] || b[i] == ' ')
		{
			if (b[i] == ' ')
				ret[j++] = ft_substr(b, 0, i);
			else
				ret[j++] = ft_substr(b, 0, i + 1);
			b += i + 1;
			while (*b && *b == ' ')
				b++;
			i = -1;
		}
	}
	ret[j] = 0;
	return (ret);
}

void	cleartrash(char **b)
{
	while (*b)
	{
		if (!ft_strchr(*b, '='))
			free(*b);
		b++;
	}
}
