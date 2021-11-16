/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:12:32 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/23 17:24:15 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	next(char **next_str, size_t *next_len, char c)
{
	size_t	i;

	*next_str += *next_len;
	*next_len = 0;
	i = 0;
	while ((*next_str)[i] == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*nextstr;
	size_t	nextlen;
	size_t	i;

	arr = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (arr == NULL)
		return (arr);
	i = 0;
	nextstr = (char *)s;
	nextlen = 0;
	while (i < count(s, c))
	{
		next(&nextstr, &nextlen, c);
		arr[i] = (char *)malloc(sizeof(char) * (nextlen + 1));
		if (arr[i] == NULL)
			return (NULL);
		ft_strlcpy(arr[i], nextstr, nextlen + 1);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
