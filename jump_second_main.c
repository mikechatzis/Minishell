/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_second_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:48:06 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/21 17:41:40 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"
#include "minishell.h"

char	*exportoutforpipes(char *b)
{
	char	*ret;

	ret = ft_calloc(1000, sizeof(char *));
	if (echoerrcheck(b))
		return ("");
	while (*b == ' ')
		b++;
	while (*b)
		b = handlescharsforpipes(b, ret);
	return (ret);
}

static size_t	count(char *b)
{
	size_t	count;

	count = 0;
	while (*b)
	{
		if (*b == '|' || *b == '<' || *b == '>')
			count++;
		b++;
	}
	return (count);
}

static size_t	calcspace(char *b, char *s, size_t i)
{
	s[i] = ' ';
	s[i + 1] = *b;
	if (b[1] == '<' || b[1] == '>')
	{
		s[i + 2] = *b;
		s[i + 3] = ' ';
		i += 4;
	}
	else
	{
		s[i + 2] = ' ';
		i += 3;
	}
	return (i);
}

char	*fixspace(char *b)
{
	char	*s;
	char	*ret;
	size_t	i;

	i = count(b);
	s = ft_calloc(sizeof(b) + (i * 2), 1);
	i = 0;
	while (*b)
	{
		if (*b == '|' || *b == '<' || *b == '>')
			i = calcspace(b, s, i);
		else
			s[i++] = *b;
		if ((*b == '<' || *b == '>')
			&& (b[1] == '<' || b[1] == '>'))
			b += 2;
		else
			b++;
	}
	ret = exportoutforpipes(s);
	free(s);
	return (ret);
}

void	second_main(char const *s)
{
	extern char		**environ;
	t_parameters	params;

	params.exit = 0;
	params.env = arraydup(environ);
	initialization(&params);
	params.line = ft_strdup(s);
	if (!params.line)
		ft_exit(NULL);
	do_comments(&params);
	if (!params.line[0] || ifspace(params.line))
		return ;
	else
		route(&params);
	freedstring(params.env);
	return ;
}
