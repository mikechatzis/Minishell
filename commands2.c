/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/12/01 18:58:24 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execexport(char *b)
{
	int		i;
	int		c;
	char	**s;
	
	b += 6;
	s = ft_split(b, ' ');
	i = 0;
	c = -1;
	while (s[++c])
	{
		while (ENV[i] && !namecmp(ENV[i], s[c]))
			i++;
		if (ft_strchr(s[c], '='))
		{
			if (ENV[i])
				free(ENV[i]);
			ENV[i] = ft_strdup(s[c]);
			i = 0;	
		}
	}
	i = 0;
	free(s);
}
