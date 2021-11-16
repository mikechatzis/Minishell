/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:15:27 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/21 16:23:25 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bzero(void *str, size_t n)
{
	unsigned char	*arr;
	int				k;

	arr = (unsigned char *)str ;
	k = 0;
	while (n > 0)
	{
		arr[k] = '\0';
		k++;
		n--;
	}
}

void	*ft_calloc(size_t elnum, size_t elsize)
{
	void	*ptr;

	ptr = NULL;
	if (elnum == 0 && elsize == 0)
	{
		elnum = 1;
		elsize = 1;
	}	
	ptr = malloc(elnum * elsize);
	if
	(ptr) ft_bzero(ptr, elnum * elsize);
	return (ptr);
}
