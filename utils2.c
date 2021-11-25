/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/25 19:55:14 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prints(char *s)
{
	if (s[0] == '\'' && !ft_strchr(&s[1], '\''))
	{
		write(2, "quote>", 6);
		return (0);
	}
	if (s[0] == '"' && !ft_strchr(&s[1], '"'))
	{
		write(2, "dquote>", 7);
		return (0);
	}
	s++;
	while (*s)
	{
		if (s[0] == '\'')
			while (*s != '\'')
			{
				write(1, &*s, 1);
				s++;
			}
		s++;
	}
	return (s);
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
