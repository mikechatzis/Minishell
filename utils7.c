/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/28 17:52:44 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*xportnmskip(char *b)
{
	while (*b == ' ')
		b++;
	if (*b == '\'' || *b == '"')
		b += 8;
	else
		b += 6;
	return (b);
}

static int	nmcont(int i, char *b)
{
	while (b[++i] && b[i] != ' ')
		continue ;
	i++;
	return (i - 1);
}

char	*parsecmdname(char *b)
{
	char	*name;
	char	*tmp;
	int		i;

	i = -1;
	while (*b == ' ')
		b++;
	if (*b == '\'' || *b == '"')
	{
		while (b[++i] && (b[i] == '\'' || b[i] == '"'))
			continue ;
		while (b[i] && b[i] != '\'' && b[i] != '"')
			i++;
		while (b[i] && (b[i] == '\'' || b[i] == '"'))
			i++;
	}
	else
		i = nmcont(i, b);
	name = ft_substr(b, 0, i);
	tmp = exportout(name);
	free(name);
	return (tmp);
}
