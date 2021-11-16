/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:05:26 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/23 17:29:27 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = NULL;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (sub);
	if (s[start] == '\0')
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < len && start < ft_strlen((char *)s))
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
