/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportarg_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:26:19 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:43:06 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	replace_string(char **array, int i, char *s)
{
	free(array[i]);
	array[i] = ft_strdup(s);
}

int	do_search(t_parameters *params, char **args, int j)
{
	char	*temp_arg;
	char	*temp_env;
	int		i;

	temp_arg = ft_strdup(args[j]);
	*(ft_strchr(temp_arg, '=')) = '\0';
	i = 0;
	while (params->env[i])
	{
		temp_env = ft_strdup(params->env[i]);
		*(ft_strchr (temp_env, '=')) = '\0';
		if (ft_strcmp(temp_env, temp_arg) == 0)
		{
			free(temp_arg);
			free(temp_env);
			return (i);
		}
		free(temp_env);
		i++;
	}
	free(temp_arg);
	return (-1);
}

char	*cut_single_quot(char *s)
{
	char	*c;
	char	*temp;
	int		len;

	len = ft_strlen(s);
	if (*(ft_strchr(s, '=') + 1) == '\'' && s[len - 1] == '\'')
	{
		s[len - 1] = '\0';
		*(ft_strchr(s, '=') + 1) = '\0';
		temp = ft_strdup(s);
		c = ft_strdup(ft_strchr(s, '=') + 2);
		free(s);
		s = ft_strjoin(temp, c);
		free(temp);
		free(c);
		return (s);
	}
	return (s);
}

char	*cut_double_quots(char *s)
{
	char	*c;
	char	*temp;
	int		len;

	len = ft_strlen(s);
	if (*(ft_strchr(s, '=') + 1) == '\"' && s[len - 1] == '\"')
	{
		s[len - 1] = '\0';
		*(ft_strchr(s, '=') + 1) = '\0';
		temp = ft_strdup(s);
		c = ft_strdup(ft_strchr(s, '=') + 2);
		free(s);
		s = ft_strjoin(temp, c);
		free(temp);
		free(c);
		return (s);
	}
	else if (*(ft_strchr(s, '=') + 1) == '\'' && s[len - 1] == '\'')
	{
		s = cut_single_quot(s);
		return (s);
	}
	return (s);
}
