/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:24:26 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:09 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

char	*qtoback(char **s)
{
	int		i;
	char	*temp;
	char	*buf;

	i = 0;
	buf = ft_strdup("\'");
	while (s[i])
	{
		temp = ft_strjoin(buf, s[i]);
		free (buf);
		buf = ft_strdup(temp);
		free(temp);
		if (i != (arrlen(s) - 1))
		{
			temp = ft_strjoin(buf, " ");
			free (buf);
			buf = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
	temp = ft_strjoin(buf, "\'");
	free (buf);
	return (temp);
}

char	*qqpasteback(char	**buf)
{
	int		i;
	char	*temp;
	char	*s;

	i = 0;
	s = ft_strdup("\"");
	while (buf[i])
	{
		temp = ft_strjoin(s, buf[i]);
		free (s);
		s = ft_strdup(temp);
		free(temp);
		if (i != (arrlen(buf) - 1))
		{
			temp = ft_strjoin(s, " ");
			free (s);
			s = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
	temp = ft_strjoin(s, "\"");
	free (s);
	return (temp);
}
