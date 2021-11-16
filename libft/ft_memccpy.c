/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:02:58 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/21 14:10:02 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *str, const void *src, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	d;
	const char		*i;
	int				k;

	arr = (unsigned char *)str;
	d = (unsigned char)c;
	i = (const char *)src;
	k = 0;
	while (n > 0)
	{
		arr[k] = i[k];
		if (i[k] == d)
			return (str + k + 1);
		else
		{
			k++;
			n--;
		}
	}
	return (NULL);
}
