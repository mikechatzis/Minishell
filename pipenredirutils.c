/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipenredirutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/27 12:18:39 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sq(char *b, int i)
{
	if (b[i] && b[i] == '\'')
	{
		while (b[i] && b[++i] != '\'')
			continue ;
		i++;
	}
	return (i);
}

int	dq(char *b, int i)
{
	if (b[i] && b[i] == '"')
	{
		while (b[i] && b[++i] != '"')
			continue ;
		i++;
	}
	return (i);
}

char	**finn(char *b, char **ret, int j)
{
	if (*b)
		ret[j++] = ft_strdup(b);
	ret[j] = 0;
	return (ret);
}

bool	checkstrayops(char *b)
{
	int	i;

	i = -1;
	while (b[++i])
		continue ;
	while (b[--i] == ' ')
		continue ;
	if (b[i] == '<' || b[i] == '>' || b[i] == '|')
	{
		printf("parse error close to token '%c'\n", b[i]);
		return (true);
	}
	return (false);
}

void	initparse(char	*b, t_nums *n)
{
	char	*buff;
	char	*name;
	char	**pr;

	buff = NULL;
	if (echoerrcheck(b))
		return ;
	name = parsecmdname(b);
	pr = checkpipesnredirs(b);
	if (!*pr)
		return (initparseret(pr, name));
	if (!pr[1])
	{
		if (checkstrayops(b))
			return (initparseret(pr, name));
		buff = exportout(b);
		parseargs(b, buff, name, n);
		n->hyphen = 1;
	}
	// else
	// 	handletruncredirs(pr);
	freedstring(pr);
	free(buff);
	free(name);
}

	// for (int k = 0; ret[k]; k++)
	// printf("|%s|\n", ret[k]);

	// for (size_t i = 0; ret[i]; i++)
	// 	printf("{%s}\n", ret[i]);