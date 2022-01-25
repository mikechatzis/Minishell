/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/25 12:22:16 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setenviron2(void)
{
	g_env[8] = ft_strjoin("__CF_USER_TEXT_ENCODING=",
			getenv("__CF_USER_TEXT_ENCODING"));
	g_env[14] = ft_strjoin("ORIGINAL_XDG_CURRENT_DESKTOP=",
			getenv("ORIGINAL_XDG_CURRENT_DESKTOP"));
	g_env[17] = ft_strjoin("TERM_PROGRAM_VERSION=",
			getenv("TERM_PROGRAM_VERSION"));
	g_env[21] = ft_strjoin("_=", getenv("_"));
}

void	setenviron(void)
{
	g_env = malloc(1000 * sizeof(char *));
	g_env[0] = ft_strjoin("PATH=", getenv("PATH"));
	g_env[1] = ft_strjoin("PWD=", getenv("PWD"));
	g_env[2] = ft_strjoin("USER=", getenv("USER"));
	g_env[3] = ft_strjoin("SECURITYSESSIONID=", getenv("SECURITYSESSIONID"));
	g_env[4] = ft_strjoin("COMMAND_MODE=", getenv("COMMAND_MODE"));
	g_env[5] = ft_strjoin("HOME=", getenv("HOME"));
	g_env[6] = ft_strjoin("SHELL=", getenv("SHELL"));
	g_env[7] = ft_strjoin("LaunchInstanceID=", getenv("LaunchInstanceID"));
	g_env[9] = ft_strjoin("XPC_SERVICE_NAME=", getenv("XPC_SERVICE_NAME"));
	g_env[10] = ft_strjoin("SSH_AUTH_SOCK=", getenv("SSH_AUTH_SOCK"));
	g_env[11] = ft_strjoin("XPC_FLAGS=", getenv("XPC_FLAGS"));
	g_env[12] = ft_strjoin("LOGNAME=", getenv("LOGNAME"));
	g_env[13] = ft_strjoin("TMPDIR=", getenv("TMPDIR"));
	g_env[15] = ft_strjoin("SHLVL=", getenv("SHLVL"));
	g_env[16] = ft_strjoin("TERM_PROGRAM=", getenv("TERM_PROGRAM"));
	g_env[18] = ft_strjoin("LANG=", getenv("LANG"));
	g_env[19] = ft_strjoin("COLORTERM=", getenv("COLORTERM"));
	g_env[20] = ft_strjoin("GIT_ASKPASS=", getenv("GIT_ASKPASS"));
	setenviron2();
	g_env[999] = 0;
}

char	**processinput(char	*b)
{
	char	**s;
	int		i;

	i = -1;
	s = xportsplit(b);
	while (s[++i])
	{
		if (isnumeric(s[i]))
			ft_bzero(s[i], ft_strlen(s[i]));
	}
	i = 0;
	return (s);
}

static int	nameeval(char *b)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (b[++i] && b[i] != '=')
	{
		if (!ft_isdigit(b[i]))
			j = 1;
	}
	return (j);
}

int	isnumeric(char *b)
{
	int		i;
	int		j;
	char	*n;

	i = -1;
	j = 0;
	j = nameeval(b);
	i = -1;
	while (b[++i] && b[i] != '=')
		if (b[i] == '#')
			j = 0;
	if (!j)
	{
		if (*b == '\'' || *b == '"')
		{
			b++;
			i--;
		}
		n = ft_substr(b, 0, i);
		printf("export: name not valid in this context: %s\n", n);
		free(n);
		return (1);
	}
	return (0);
}
