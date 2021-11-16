/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:06:55 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/22 13:19:49 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*bi;
	size_t	count;
	size_t	llen;
	size_t	i;

	bi = (char *)big;
	llen = ft_strlen(little);
	count = 0;
	i = 0;
	if (*little == '\0' || bi == little)
		return ((char *)bi);
	while (bi[i] != '\0' && count < len)
	{
		count = 0;
		while (bi[i + count] != '\0' && little[count] != '\0'
			&& bi[i + count] == little[count] && i + count < len)
			count++;
		if (count == llen)
			return (bi + i);
		i++;
	}
	return (NULL);
}
