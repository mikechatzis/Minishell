/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/20 16:27:16 by mchatzip         ###   ########.fr       */
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
