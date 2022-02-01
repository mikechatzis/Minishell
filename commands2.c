/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/01 16:12:34 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execexport(char *b)
{
	int		i;
	int		c;
	char	**s;

	b = xportnmskip(b);
	i = 0;
	c = -1;
	if (echoerrcheck(b))
		return ;
	s = processinput(b);
	while (s[++c])
	{
		i = incrementi(i, s[c]);
		if (ft_strchr(s[c], '='))
		{
			if (g_env[i])
				free(g_env[i]);
			evalquotes(exportout(s[c]));
			g_env[i] = ft_strdup(exportout(s[c]));
		}
		i = 0;
	}
	free(s);
	cleartrash(g_env);
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
	if (b)
		printenv();
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
			printf("export/unset: name not valid in this context: %s\n", n);
			free(n);
			return ;
		}
	}
}

/*ADDITIONAL ENV (IF NEEDED)*/

	// int	i;
	// char	*s;
	// char	*sav;
	// char	*sub;
	// char	**sp;

	// i = 0;
	// sp = ft_split(b, ' ');
	// s = ft_strjoin("export ", &b[3]);
	// sub = ft_strnstr(b, "./", ft_strlen(b));
	// sav = saveenv();
	// while (sp[i] && (ft_strchr(sp[i], '=')
	// 		|| (!ft_strncmp(sp[i], "env", 3) && i == 0)))
	// 	i++;
	// execexport(s);
	// if (sp[i] && !ft_strchr(sp[i], '='))
	// 	execinenv(i, s, sub, sp);
	// else

	// restoreenv(sav);
	// free3(s, sp, sav);