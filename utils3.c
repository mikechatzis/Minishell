/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/12/13 14:50:03 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	namecmpu(char *s, char *b)
{
	if (ft_strncmp(s, b, ft_strlen(b)) || !*s)
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
	while (ENV[++j])
	{
		while (ENV[j][++i])
			s[++k] = ENV[j][i];
		s[++k] = ' ';
		i = -1;
	}
	return (s);
}

void	restoreenv(char *s)
{
	free(ENV);
	ENV = ft_split(s, ' ');
}

void	free3(void *s, void *sp, void *sav)
{
	free(s);
	free(sp);
	free(sav);
}
 