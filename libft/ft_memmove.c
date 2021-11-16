/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:01:51 by mchatzip          #+#    #+#             */
/*   Updated: 2021/07/08 14:51:19 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	const char	*lasts;
	char		*lastd;

	d = (char *)dest;
	s = (const char *)src;
	lasts = s + (len - 1);
	lastd = d + (len - 1);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
