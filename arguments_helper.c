/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:31:55 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:01 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	quot_handle_2(char **string, size_t *i, size_t *len)
{
	if ((*string)[*i] == '\"' && ft_strchr(&(*string)[*i + 1], '\"'))
	{
		(*len)++;
		(*i)++;
		while ((*string)[*i] != '\"')
		{
			(*i)++;
			(*len)++;
		}
	}
	if ((*string)[*i] == '\'' && ft_strchr(&(*string)[*i + 1], '\''))
	{
		(*len)++;
		(*i)++;
		while ((*string)[*i] != '\'')
		{
			(*i)++;
			(*len)++;
		}
	}
}

void	quot_handle(const char *s, size_t *i)
{
	if (s[*i] == '\"' && ft_strchr(&s[*i + 1], '\"'))
	{
		(*i)++;
		while (s[*i] != '\"')
			(*i)++;
	}
	if (s[*i] == '\'' && ft_strchr(&s[*i + 1], '\''))
	{
		(*i)++;
		while (s[*i] != '\'')
			(*i)++;
	}
}

void	next_argument(char **string, size_t *len, char c)
{
	size_t	i;

	*string += *len;
	*len = 0;
	i = 0;
	while ((*string)[i] == c)
		(*string)++;
	while ((*string)[i])
	{
		quot_handle_2(&(*string), &i, len);
		if ((*string)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

size_t	arguments_counter(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	if (!s[0])
		return (0);
	i = 0;
	counter = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		quot_handle(s, &i);
		if (s[i] == c)
		{
			counter++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		counter++;
	return (counter);
}
