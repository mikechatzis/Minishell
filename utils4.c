/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/11 17:12:21 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setenviron2(void)
{
	ENV[21] = ft_strjoin("_=", getenv("_"));
}

void	setenviron(void)
{
	ENV = malloc(1000 * sizeof(char *));
	ENV[0] = ft_strjoin("PATH=", getenv("PATH"));
	ENV[1] = ft_strjoin("PWD=", getenv("PWD"));
	ENV[2] = ft_strjoin("USER=", getenv("USER"));
	ENV[3] = ft_strjoin("SECURITYSESSIONID=", getenv("SECURITYSESSIONID"));
	ENV[4] = ft_strjoin("COMMAND_MODE=", getenv("COMMAND_MODE"));
	ENV[5] = ft_strjoin("HOME=", getenv("HOME"));
	ENV[6] = ft_strjoin("SHELL=", getenv("SHELL"));
	ENV[7] = ft_strjoin("LaunchInstanceID=", getenv("LaunchInstanceID"));
	ENV[8] = ft_strjoin("__CF_USER_TEXT_ENCODING=", getenv("__CF_USER_TEXT_ENCODING"));
	ENV[9] = ft_strjoin("XPC_SERVICE_NAME=", getenv("XPC_SERVICE_NAME"));
	ENV[10] = ft_strjoin("SSH_AUTH_SOCK=", getenv("SSH_AUTH_SOCK"));
	ENV[11] = ft_strjoin("XPC_FLAGS=", getenv("XPC_FLAGS"));
	ENV[12] = ft_strjoin("LOGNAME=", getenv("LOGNAME"));
	ENV[13] = ft_strjoin("TMPDIR=", getenv("TMPDIR"));
	ENV[14] = ft_strjoin("ORIGINAL_XDG_CURRENT_DESKTOP=", getenv("ORIGINAL_XDG_CURRENT_DESKTOP"));
	ENV[15] = ft_strjoin("SHLVL=", getenv("SHLVL"));
	ENV[16] = ft_strjoin("TERM_PROGRAM=", getenv("TERM_PROGRAM"));
	ENV[17] = ft_strjoin("TERM_PROGRAM_VERSION=", getenv("TERM_PROGRAM_VERSION"));
	ENV[18] = ft_strjoin("LANG=", getenv("LANG"));
	ENV[19] = ft_strjoin("COLORTERM=", getenv("COLORTERM"));
	ENV[20] = ft_strjoin("GIT_ASKPASS=", getenv("GIT_ASKPASS"));
	setenviron2();
	ENV[999] = 0;
}
