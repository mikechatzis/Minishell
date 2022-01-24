/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/24 19:25:18 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execexport(char *b)
{
	int		i;
	int		c;
	char	**s;

	b += 6;
	i = 0;
	c = -1;
	if (echoerrcheck(b))
		return ;
	s = processinput(b);
	while (s[++c])
	{
		while (g_env[i] && (!namecmp(g_env[i], s[c]) || !g_env[i][0]))
			i++;
		if (ft_strchr(s[c], '='))
		{
			if (g_env[i])
				free(g_env[i]);
			g_env[i] = exportout(s[c]);
			evalquotes(g_env[i]);
		}
		i = 0;
	}
	free(s);
}

void	execunset(char *b)
{
	char	**s;
	int		c;
	int		i;

	b += 5;
	c = -1;
	i = -1;
	if (echoerrcheck(b))
		return ;
	s = processinput(b);
	while (s[++c])
	{
		while (g_env[++i])
			if (!namecmpu(g_env[i], s[c]))
				ft_bzero(g_env[i], ft_strlen(g_env[i]));
		i = -1;
	}
	free(s);
}

void	execenv(char *b)
{
	int		i;
	char	*s;
	char	*sav;
	char	*sub;
	char	**sp;

	i = 0;
	sp = ft_split(b, ' ');
	s = ft_strjoin("export ", &b[3]);
	sub = ft_strnstr(b, "./", ft_strlen(b));
	sav = saveenv();
	while (sp[i] && (ft_strchr(sp[i], '=')
			|| (!ft_strncmp(sp[i], "env", 3) && i == 0)))
		i++;
	execexport(s);
	if (sp[i] && !ft_strchr(sp[i], '='))
		execinenv(i, s, sub, sp);
	else
		printenv();
	restoreenv(sav);
	free3(s, sp, sav);
}

void	evalquotes(char	*s)
{
	char	*n;
	int		i;

	i = -1;
	while (s[++i] && s[i] != '=')
	{
		if (s[i] == '\'' || s[i] == '"')
		{
			while (s[i] && s[i] != '=')
				i++;
			n = ft_substr(s, 0, i);
			printf("export: name not valid in this context: %s\n", n);
			free(n);
			return ;
		}
	}
}
