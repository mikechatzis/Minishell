/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/20 16:03:43 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echoerrcheck(char *b)
{
	int	i;

	i = -1;
	while (b[++i])
	{
		i = squoteerr(i, b);
		if (i == -1)
			return (-1);
		i = dquoteerr(i, b);
		if (i == -1)
			return (-1);
	}
	return (0);
}

int	namecmp(char *s, char *b)
{
	while (*s && *b)
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
		while (s[i] && s[i] != ' '
			&& s[i] != '$' && s[i] != '"' && s[i] != '\'')
			i++;
		name = ft_substr(&s[1], 0, i - 1);
		if (!*name)
			s = emptyname(s);
		else if (s[1] == '0' || s[1] == '#')
			s = zeroorhash(s);
		else
		{
			b = parseenv(g_env, name);
			s = allelse(b, s, name);
		}
		free(name);
		if (*s != '$')
			break ;
	}
	return (s);
}

void	execinenv(int i, char *s, char *sub, char **sp)
{
	if (!ft_strnstr(sp[i], "./", ft_strlen(sp[i])))
		printf("./%s: no such file or directory\n", sp[i]);
	else if (sub)
		exec(sub);
	else
	{
		free(s);
		s = ft_strjoin("./", sp[i]);
		exec(s);
	}
}
