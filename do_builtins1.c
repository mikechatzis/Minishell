/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtins1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:21:02 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:27 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	do_unset(t_parameters *params, char **args)
{
	if (params->n_pipe == 0)
	{
		i_handler(params, args);
		o_handler(params, args);
	}
	if (params->n_pipe > 0 || !args[1])
	{
		params->exit_status = 1;
		return ;
	}
	if (unset_helper1(params, args) > 0)
	{
		params->env = unset_helper2(params->env, unset_helper1(params, args));
		params->exit_status = 0;
	}
	else
	{
		params->exit_status = 1;
		return ;
	}
}

void	do_export(t_parameters *params, char **args)
{
	if (params->n_pipe == 0)
	{
		i_handler(params, args);
		o_handler(params, args);
	}
	if (!args[1])
		exit(sort_print(params));
	else
	{
		if (params->n_pipe > 0)
		{
			params->exit_status = 0;
			return ;
		}
		if (check_digit(args[1]))
		{
			params->exit_status = 1;
			return ;
		}
		exportarg(params, args);
	}
}

void	do_cd(t_parameters *params, char **args)
{
	if (params->n_pipe > 0)
		return ;
	i_handler(params, args);
	if (params->input_flag)
		delete_last(args);
	o_handler(params, args);
	if (!args[1] || (args[1] && ft_strcmp(args[1], "~") == 0
			&& ft_strlen(args[1]) == 1))
		chdir (getenv ("HOME"));
	else if (args[1])
	{
		if (args[2])
		{
			printf("bash: cd: too many arguments\n");
			params->exit_status = 1;
			return ;
		}
		else if (chdir(args[1]) != 0)
		{
			printf("bash: cd: %s: No such file or directory\n", args[1]);
			params->exit_status = 1;
			return ;
		}
	}
	params->exit_status = 0;
}

void	do_pwd(t_parameters *params, char **args)
{
	char	cwd[10000];

	(void)args;
	(void)params;
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	exit(EXIT_SUCCESS);
}

void	do_echo(t_parameters *params, char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (args[i])
	{
		if (i == 1 && n_checker(args[i]))
		{
			j = 0;
			i++;
			while (args[i] && n_checker(args[i]))
				i++;
			if (!args[i])
				exit(EXIT_SUCCESS);
		}
		ft_put(params, args, i);
		i++;
	}
	if (j == 1)
		ft_putstr_fd("\n", params->fd_io[1]);
	freesplit(args);
	exit(EXIT_SUCCESS);
}
