/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:45:19 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/22 13:29:41 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	destlen;
	size_t	srclen;
	char	*sr;

	sr = (char *)src;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	k = destlen;
	i = 0;
	if (destlen < size - 1 && size > 0)
	{
		while (sr[i] && destlen + i < size - 1)
		{
			dst[k] = sr[i];
			k++;
			i++;
		}
		dst[k] = 0;
	}
	if (destlen >= size)
		destlen = size;
	return (destlen + srclen);
}
