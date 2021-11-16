/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:46:41 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/22 12:43:20 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return (*s1 - *s2);
		else
		{
			s1++;
			s2++;
			n--;
		}	
	}
	return (0);
}
