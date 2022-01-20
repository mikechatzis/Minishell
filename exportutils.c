/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/20 16:41:01 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handlesquotes(char *b)
{
	char	*buff;
	int		i;

	b++;
	i = 0;
	while (b[i] && b[i] != '\'')
		i++;
	buff = ft_substr(b, 0, i);
	printf("%s", buff);
	b += ft_strlen(buff) + 1;
	free(buff);
	return (b);
}

char	*handledquotes(char *b)
{
	char	*buff;
	int		i;

	b++;
	i = 0;
	while (b[i] && b[i] != '"')
		i++;
	buff = ft_substr(b, 0, i);
	b += ft_strlen(buff) + 1;
	i = ft_strlen(buff);
	while (*buff)
	{
		if (*buff == '$')
			buff = printvar(buff);
		printf("%c", *buff);
		if (*buff)
			buff++;
	}
	buff -= i;
	free(buff);
	return (b);
}

char	*handlespacexp(char *b)
{
	printf(" ");
	while (*b == ' ')
		b++;
	return (b);
}

char	*handlescharsxp(char	*b)
{
	if (*b == ' ')
		b = handlespace(b);
	if (*b == '\'')
		b = handlesquotes(b);
	if (*b == '"')
		b = handledquotes(b);
	if (*b == '$')
		b = printvar(b);
	if (*b != ' ' && *b != '$' && *b != '\'' && *b != '"')
	{
		printf("%c", *b);
		b++;
	}
	return (b);
}

char	*exportout(char *b)
{
	char	*buff;

	while (*b)
		b = handlescharsxp(b);
	return (buff);
}
