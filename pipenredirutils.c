/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipenredirutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/26 17:08:12 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sq(char *b, int i)
{
	if (b[i] == '\'')
	{
		while (b[++i] != '\'')
			continue ;
		i++;
	}
	return (i);
}

int	dq(char *b, int i)
{
	if (b[i] == '"')
	{
		while (b[++i] != '"')
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

void	initparse(char	*b, t_nums *nums)
{
	char	*buff;
	char	**pr;

	loghistory(b, nums);
	if (echoerrcheck(b))
		return ;
	pr = checkpipesnredirs(b);
	if (!*pr)
	{
		free(pr);
		return ;	
	}
	if (!pr[1])
	{
		if (checkstrayops(b))
		{
			free(pr);
			return ;
		}
		buff = ft_strdup(exportout(b));
		parseargs(buff);
		free(buff);
		free(pr);
	}
	//else to be added for pipes/redirections handling
}

	// for (int k = 0; ret[k]; k++)
	// printf("|%s|\n", ret[k]);