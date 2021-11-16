/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:02:09 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/22 12:12:55 by mchatzip         ###   ########.fr       */
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

static size_t	strtriml(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;
	size_t	l;

	i = 0;
	k = 0;
	l = 0;
	while (s1[i] && set[k])
	{
		if (s1[i] != set[k])
			k++;
		else if (s1[i] == set[k])
		{
			i++;
			l++;
			k = 0;
		}
	}
	return (l);
}

static size_t	strtrimr(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;
	size_t	l;
	size_t	setl;
	size_t	s1l;

	i = 0;
	k = 0;
	l = 0;
	setl = ft_strlen(set);
	s1l = ft_strlen(s1);
	while (k < setl && set[setl - 1 - k] != '\0')
	{
		if (s1[s1l - 1 - i] != set[setl - 1 - k])
			k++;
		else if (s1[s1l - 1 - i] == set[setl - 1 - k])
		{
			i++;
			l++;
			k = 0;
		}
	}
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*f;
	size_t	i;
	size_t	k;
	size_t	s1l;
	size_t	r;

	f = (char *)malloc(ft_strlen(s1) + 1);
	i = strtriml(s1, set);
	k = 0;
	s1l = ft_strlen(s1);
	r = strtrimr(s1, set);
	if (f == NULL)
		return (NULL);
	while (s1[i] && i < s1l - r)
	{
		f[k] = s1[i];
		i++;
		k++;
	}
	f[k] = '\0';
	return (f);
}
