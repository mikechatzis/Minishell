/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:14:44 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/20 19:47:49 by mchatzip         ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*k;
	unsigned int		i;
	unsigned int		len;

	len = ft_strlen(s);
	i = 0;
	k = malloc(len + 1);
	if (s == NULL || f == NULL || k == NULL)
		return (NULL);
	while (s[i])
	{
		k[i] = f(i, s[i]);
		i++;
	}
	k[i] = '\0';
	return (k);
}
