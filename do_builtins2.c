/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtins2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:20:42 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:31 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	do_exit(char **args)
{
	char	*temp;
	int		i;

	if (args && args[1])
	{
		temp = args[1];
		i = ft_atoi(temp);
		exit(i);
	}
	else
		exit (EXIT_SUCCESS);
}

void	do_env(t_parameters *params, char **args)
{
	int	i;

	i = 0;
	if (args[1])
	{
		printf("env: `%s\': No such file or directory\n", args[1]);
		exit(127);
	}
	else
	{
		while (params->env[i])
		{
			printf("%s\n", params->env[i]);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
}
