/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:51:06 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:44:21 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

int	unset_helper1(t_parameters *params, char **args)
{
	char	*temp_env;
	int		i;

	i = 0;
	while (params->env[i])
	{
		temp_env = ft_strdup(params->env[i]);
		*(ft_strchr(temp_env, '=')) = '\0';
		if (ft_strcmp(temp_env, args[1]) == 0)
		{
			free (temp_env);
			return (i);
		}
		free (temp_env);
		i++;
	}
	return (-1);
}

char	**unset_helper2(char **array, int i)
{
	int		j;
	int		k;
	char	**new;

	j = 0;
	k = 0;
	new = (char **)malloc(sizeof(char *) * (arrlen(array) + 1));
	while (j < arrlen(array))
	{
		if (i == j)
			j++;
		new[k] = ft_strdup(array[j]);
		j++;
		k++;
	}
	new[k] = NULL;
	freesplit(array);
	return (new);
}
