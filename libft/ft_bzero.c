/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 08:53:53 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/21 16:23:19 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *str, size_t n)
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
