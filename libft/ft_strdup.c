/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:37:46 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/21 12:39:06 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memcpy(void *str, const void *c, size_t n)
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
	arr[k] = '\0';
	return (str);
}

static size_t	ft_strlen(const char *c)
{
	int	len;

	len = 0;
	while (*c != '\0')
	{
		c++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src) + 1;
	dst = malloc((len) + 1);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, len);
	return (dst);
}
