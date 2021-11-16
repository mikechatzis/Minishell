/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:11:45 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/22 14:25:42 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = 0;
	while (s[i])
	{
		if (s[i] == c)
			p = (char *)(s + i);
		i++;
	}
	if (s[i] == c)
		p = (char *)(s + i);
	return (p);
}
