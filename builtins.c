/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:12:47 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:15 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

int	check_builtin(char *command)
{
	int	len;

	len = ft_strlen(command);
	if (!ft_strcmp(command, "echo") && len == 4)
		return (1);
	else if (!ft_strcmp(command, "cd") && len == 2)
		return (1);
	else if (!ft_strcmp(command, "pwd") && len == 3)
		return (1);
	else if (!ft_strcmp(command, "export") && len == 6)
		return (1);
	else if (!ft_strcmp(command, "unset") && len == 5)
		return (1);
	else if (!ft_strcmp(command, "env") && len == 3)
		return (1);
	else if (!ft_strcmp(command, "exit") && len == 4)
		return (1);
	else
		return (0);
}

void	builtins_jumper(t_parameters *params, char **args)
{
	char	*c;

	c = args[pass_executable(args)];
	c = check(params, c);
	if (!ft_strcmp(c, "echo"))
		do_echo(params, args);
	else if (!ft_strcmp(c, "pwd"))
		do_pwd(params, args);
	else if (!ft_strcmp(c, "cd"))
		do_cd(params, args);
	else if (!ft_strcmp(c, "export"))
		do_export(params, args);
	else if (!ft_strcmp(c, "env"))
		do_env(params, args);
	else if (!ft_strcmp(c, "exit"))
		do_exit(args);
}
