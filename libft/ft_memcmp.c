/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:36:40 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/21 13:48:34 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*strx1;
	unsigned char	*strx2;

	strx1 = (unsigned char *)str1;
	strx2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*strx1 != *strx2)
			return (*strx1 - *strx2);
		else
		{
			strx1++;
			strx2++;
			n--;
		}	
	}
	return (0);
}
