/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:53:43 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/14 10:57:17 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			k;
	unsigned char	*arr;
	unsigned char	i;

	arr = (unsigned char *)s;
	i = (unsigned char)c;
	k = 0;
	while (n > k)
	{
		if (*arr == i)
		{
			return (arr);
		}
		arr++;
		k++;
	}
	return (NULL);
}
