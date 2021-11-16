/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:38:51 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/12 17:35:58 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	i;
	int				k;

	arr = (unsigned char *)str ;
	i = (unsigned char)c;
	k = 0;
	while (n > 0)
	{
		arr[k] = i;
		k++;
		n--;
	}
	return (str);
}
