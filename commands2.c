/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/12/09 14:47:35 by mchatzip         ###   ########.fr       */
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
	char	*sub;
	char	**sp;

	i = 0;
	sp = ft_split(b, ' ');
	s = ft_strjoin("export ", &b[3]);
	sub = ft_strnstr(b, "./", ft_strlen(b));
	while (sp[i] && (ft_strchr(sp[i], '=') || (!ft_strncmp(sp[i], "env", 3) && i == 0)))
		i++;
	execexport(s);
	if (sp[i] && !ft_strchr(sp[i], '='))
	{
		if (!ft_strnstr(sp[i], "./", ft_strlen(sp[i])))
			printf("./%s: no such file or directory\n", sp[i]);
		else if (sub)
			exec(sub);
		else
		{
			free(s);
			s = ft_strjoin("./", sp[i]);
			exec(s);
		}
	}
	else
	{
		i = -1;
		while (ENV[++i] && *ENV[i])
			printf("%s\n", ENV[i]);
	}
	execunset(s);
	free(s);
	free(sp);
}
