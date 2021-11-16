/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:26:13 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/21 12:43:24 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cx;

	cx = (unsigned char)c;
	while (*s != '\0' && *s != cx)
	{
		s++;
	}
	if (*s == '\0' && cx != '\0')
		return (NULL);
	else
		return ((char *)s);
}
