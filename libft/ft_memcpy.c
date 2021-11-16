/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:24:03 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/13 09:40:50 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *str, const void *c, size_t n)
{
	unsigned char	*arr;
	const char		*i;
	int				k;

	arr = (unsigned char *)str ;
	i = (const char *)c;
	k = 0;
	while (n > 0)
	{
		arr[k] = i[k];
		k++;
		n--;
	}
	return (str);
}
