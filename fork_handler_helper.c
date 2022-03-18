/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handler_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:12:21 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:43:13 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

/*check command if it is forkable*/

int	check_command(char	*command, char *next_command)
{
	if (!command)
		return (1);
	if (!ft_strcmp(command, "echo") && ft_strlen(command) == 4)
		return (1);
	else if (!ft_strcmp(command, "pwd") && ft_strlen(command) == 3)
		return (1);
	else if (!ft_strcmp(command, "env") && ft_strlen(command) == 3)
		return (1);
	else if (!ft_strcmp(command, "export") && ft_strlen(command) == 6)
	{
		if (next_command && next_command[0] != '>')
			return (0);
		else
			return (1);
	}
	else if (!ft_strcmp(command, "cd") && ft_strlen(command) == 2)
		return (0);
	else if (!ft_strcmp(command, "unset") && ft_strlen(command) == 5)
		return (0);
	else if (!ft_strcmp(command, "exit") && ft_strlen(command) == 4)
		return (0);
	else
		return (1);
}

int	pass_executable(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strcmp(args[i], "<") && args[i + 1])
		{
			i += 2;
			continue ;
		}
		else if (!ft_strcmp(args[i], "<<") && args[i + 1])
		{
			i += 2;
			continue ;
		}
		else if (args[i][0] == '<' && args[i][1] != '<' && ++i)
			continue ;
		else if (args[i][0] == '<' && args[i][1] == '<' && args[i][2] && ++i)
			continue ;
		else
			break ;
	}
	return (i);
}

char	*check(t_parameters *params, char *s)
{
	char	*p;
	int		len;

	if (!s)
		return (NULL);
	if (!(ft_strchr(s, '$')))
		return (s);
	len = ft_strlen(s);
	if (s[0] == '\'' && s[len - 1 == '\''])
		return (s);
	else if (s[0] == '\"' && s[len - 1] == '\"')
	{
		s[len - 1] = '\0';
		p = double_quot(params, &s[1]);
		free (s);
	}
	else if (ft_strchr(s, '$'))
		p = parse_v(params, s);
	else
		return (NULL);
	return (p);
}

char	*trimmer(char *s)
{
	char	*temp;
	int		len;

	len = ft_strlen(s);
	if (s[0] == '\'' && s[len - 1] == '\'')
	{
		s[len - 1] = '\0';
		temp = ft_strdup(&s[1]);
		free(s);
		return (temp);
	}
	else if (s[0] == '\"' && s[len - 1] == '\"')
	{
		s[len - 1] = '\0';
		temp = ft_strdup(&s[1]);
		free(s);
		return (temp);
	}
	return (s);
}

void	env_handler(t_parameters *params, char **command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		command[i] = check(params, command[i]);
		command[i] = trimmer(command[i]);
		i++;
	}
}
