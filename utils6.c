/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/07 13:19:44 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	squoteerr(int i, char *b)
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
	return (i);
}

int	dquoteerr(int i, char *b)
{
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
	return (i);
}

void	printenv(void)
{
	int	i;

	i = -1;
	while (g_env[++i])
		if (g_env[i][0])
			printf("%s\n", g_env[i]);
}

static char	*mngbuff(char *s)
{
	char	*buff;

	if (*s == '\'')
		buff = ft_strtrim(s, "'");
	else
		buff = ft_strtrim(s, "\"");
	return (buff);
}

char	*handlenflag(char *b)
{
	char	**s;
	char	*buff;
	int		i;
	size_t	j;

	s = ft_split(b, ' ');
	i = -1;
	j = 0;
	while (s[++i])
	{
		buff = mngbuff(s[i]);
		if (!ft_strnstr(buff, "-n", 2))
			break ;
		while (buff[++j])
			if (buff[j] != 'n')
				break ;
		if (j == ft_strlen(buff))
			b += ft_strlen(s[i]) + 1;
		free(buff);
		j = 0;
	}
	freedstring(s);
	return (b);
}
