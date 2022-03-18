/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfthelper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:16:24 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:44:01 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

char	*newstring(size_t	size)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	s[size] = '\0';
	while (size)
	{
		size--;
		s[size] = '\0';
	}
	return (s);
}

char	*addchar(char *str, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str || !c)
		return (NULL);
	res = newstring(ft_strlen(str) + 2);
	if (!res)
		return (NULL);
	while (i < ft_strlen(str))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	i++;
	res[i] = '\0';
	free(str);
	return (res);
}

int	freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (0);
}

int	arrlen(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*envget(t_parameters *params, char *str)
{
	int		i;
	char	*temp_env;

	i = 0;
	while (params->env[i])
	{
		temp_env = ft_strdup(params->env[i]);
		*(ft_strchr(temp_env, '=')) = '\0';
		if (ft_strcmp(temp_env, str) == 0)
		{
			free(temp_env);
			return (ft_strchr(params->env[i], '=') + 1);
		}
		free(temp_env);
		i++;
	}
	return (NULL);
}
