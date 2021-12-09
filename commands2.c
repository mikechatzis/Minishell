/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/12/09 12:28:24 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execexport(char *b)
{
	int		i;
	int		c;
	char	**s;
	
	b += 6;
	s = ft_split(b, ' ');
	i = 0;
	c = -1;
	while (s[++c])
	{
		while (ENV[i] && *ENV[i] && !namecmp(ENV[i], s[c]))
			i++;
		if (ft_strchr(s[c], '='))
		{
			if (ENV[i])
				free(ENV[i]);
			if (*s[c] != '=')
				ENV[i] = ft_strdup(s[c]);
			i = 0;	
		}
	}
	i = 0;
	free(s);
}

void	execunset(char *b)
{
	char	**s;
	int		c;
	int		i;

	b += 5;
	c = -1;
	i = 0;
	s = ft_split(b, ' ');
	while (s[++c])
	{
		while (ENV[i] && namecmpu(ENV[i], s[c]))
			i++;
		if (ENV[i])
			ft_bzero(ENV[i], ft_strlen(ENV[i]));
		i = 0;
	}
	free(s);
}

void	execenv(char *b)
{
	int		i;
	char	*s;
	char	*ex;

	i = -1;
	ex = ft_strnstr(b, "./", ft_strlen(b));
	s = ft_strjoin("export ", &b[3]);
	if (ft_strchr(b, '='))
		execexport(s);
	if (ex)
		exec(ex);
	if (!ex)
	{
		while (ENV[++i] && *ENV[i])
			printf("%s\n", ENV[i]);
	}
	if (ft_strchr(b, '='))
		execunset(s);
	free(s);
}
