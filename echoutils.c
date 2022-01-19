/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echoutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/19 15:30:59 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handlespace(char *b)
{
	printf(" ");
	while (*b == ' ')
		b++;
	return (b);
}

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

char	*singledollar(char *b)
{
	printf("$");
	b += 1;
	return(b);
}

char	*handlepiddis(char *b)
{
	b += 2;
	printf("%d", getpid());
	return (b);
}
