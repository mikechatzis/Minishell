/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:30:35 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/21 15:18:09 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		i;
	int		k;

	k = 0;
	i = 0;
	cat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (cat == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{	
		cat[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{	
		cat[i] = s2[k];
		i++;
		k++;
	}
	cat[i] = '\0';
	return (cat);
}
