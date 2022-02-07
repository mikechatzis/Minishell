/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/07 13:21:51 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	namecmpu(char *s, char *b)
{
	if (ft_strncmp(s, b, ft_strlen(b)))
		return (1);
	return (0);
}

int	namecmpx(char **s, char *b)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!namecmpu(s[i], b))
			return (1);
	return (0);
}

char	*saveenv(void)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = -1;
	s = malloc(1000);
	ft_bzero(s, 1000);
	while (g_env[++j])
	{
		while (g_env[j][++i])
			s[++k] = g_env[j][i];
		s[++k] = ' ';
		i = -1;
	}
	return (s);
}

void	restoreenv(char *s)
{
	int		i;
	char	**sp;

	i = -1;
	free(g_env);
	g_env = malloc(1000 * sizeof(char *));
	sp = ft_split(s, ' ');
	while (sp[++i])
		g_env[i] = ft_strdup(sp[i]);
	g_env[999] = 0;
	free(sp);
}

void	free3(void *s, void *sp, void *sav)
{
	if (s)
		free(s);
	if (sp)
		free(sp);
	if (sav)
		free(sav);
}
