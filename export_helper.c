/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:49:48 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:43:03 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	exportarg(t_parameters *params, char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (!ft_strchr(args[i], '='))
			return ;
		args[i] = cut_double_quots(args[i]);
		if (do_search (params, args, i) < 0)
			params->env = strarrayadd(params->env, args[i]);
		else
			replace_string(params->env, do_search(params, args, i), args[i]);
		i++;
	}
}

int	check_digit(char *s)
{
	if (!s)
		return (-1);
	if (ft_isdigit(s[0]) || s[0] == '=' || s[0] == '?')
	{
		printf("bash: export: `%s': not a valid identifier\n", s);
		return (-1);
	}
	return (0);
}

void	go_sort(char **array, int len)
{
	char	*temp;
	int		i;
	int		sw;

	i = 0;
	sw = 1;
	while (sw == 1)
	{
		sw = 0;
		i = 0;
		while (i < len - 1)
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
			{
				temp = ft_strdup(array[i]);
				free (array[i]);
				array[i] = ft_strdup(array[i + 1]);
				free (array[i + 1]);
				array[i + 1] = ft_strdup(temp);
				free(temp);
				sw = 1;
			}
			i++;
		}
	}
}

void	add_q(char **array)
{
	char	*c1;
	char	*c2;
	int		i;

	i = 0;
	while (array[i])
	{
		*(ft_strchr(array[i], '=')) = '\0';
		c1 = ft_strjoin(array[i], "=\"");
		c2 = ft_strjoin(c1, &array[i][ft_strlen(array[i]) + 1]);
		free(array[i]);
		array[i] = ft_strjoin(c2, "\"");
		free(c1);
		free(c2);
		i++;
	}
}

int	sort_print(t_parameters *params)
{
	char	**env_cpy;
	int		i;

	i = 0;
	env_cpy = arrdup(params->env);
	go_sort(env_cpy, arrlen(env_cpy));
	add_q(env_cpy);
	while (env_cpy[i])
		printf ("declare -x %s\n", env_cpy[i++]);
	freesplit(env_cpy);
	return (EXIT_SUCCESS);
}
