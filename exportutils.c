/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/24 15:28:10 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handlesquotesxp(char *b, char *ret)
{
	char	*buff;
	int		i;

	b++;
	i = 0;
	while (b[i] && b[i] != '\'')
		i++;
	buff = ft_substr(b, 0, i);
	ft_strncat(ret, buff, ft_strlen(buff));
	b += ft_strlen(buff) + 1;
	free(buff);
	return (b);
}

static char	*handledquotesxp(char *b, char *ret)
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
			buff = printvarxp(buff, ret);
		if (*buff)
		{
			ft_strncat(ret, &*buff, 1);
			buff++;
		}
	}
	buff -= i;
	free(buff);
	return (b);
}

static char	*handlespacexp(char *b, char *ret)
{
	ft_strncat(ret, " ", 1);
	while (*b == ' ')
		b++;
	return (b);
}

char	*handlescharsxp(char *b, char *ret)
{
	if (*b == ' ')
		b = handlespacexp(b, ret);
	if (*b == '\'')
		b = handlesquotesxp(b, ret);
	if (*b == '"')
		b = handledquotesxp(b, ret);
	if (*b == '$')
		b = printvarxp(b, ret);
	if (*b == '~')
		b = handlehyphen(b, ret);
	if (*b && *b != ' ' && *b != '$' && *b != '\'' && *b != '"')
	{
		ft_strncat(ret, &*b, 1);
		b++;
	}
	return (b);
}

char	*exportout(char *b)
{
	char	*ret;

	ret = ft_calloc(1000, sizeof(char *));
	if (echoerrcheck(b))
		return ("");
	while (*b == ' ')
		b++;
	while (*b)
		b = handlescharsxp(b, ret);
	return (ret);
}
