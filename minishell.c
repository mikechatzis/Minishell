/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/02/15 15:37:32 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	evalchar(char *b, int i)
{
	if (b[i] == '|' && (b[i + 1] == '|' || b[i + 1] == '<' || b[i + 1] == '>'))
	{
		printf("syntax error close to token: '|'\n");
		return (-1);
	}
	i = handlerightredir(b, i);
	if (i != -1)
		i = handleleftredir(b, i);
	return (++i);
}

char	**checkpipesnredirs(char *b)
{
	int		i;
	int		j;
	char	**ret;

	i = -1;
	j = 0;
	ret = ft_calloc(1000, 1000);
	while (b[++i])
	{
		i = sq(b, i);
		i = dq(b, i);
		if (b[i] == '|' || b[i] == '<' || b[i] == '>')
		{
			i = evalchar(b, i);
			if (i == -1)
				return (ret);
			ret[j++] = ft_substr(b, 0, i);
			b += i;
			i = -1;
		}
	}
	return (finn(b, ret, j));
}

void	parseargs(char *b, char *buff, char *name, t_nums *n)
{
	if (!ft_strncmp(name, "exit", ft_strlen(name)))
		execexit(b, buff, name, n);
	else if (!ft_strncmp(name, "pwd", ft_strlen(name)))
		execpwd();
	else if (!ft_strncmp(name, "cd", ft_strlen(name)))
		execcd(buff);
	else if (!ft_strncmp(name, "./", 2))
		exec(buff);
	else if (!ft_strncmp(name, "echo", ft_strlen(name)))
		exececho(buff);
	else if (!ft_strncmp(name, "export", ft_strlen(name)))
		execexport(b);
	else if (!ft_strncmp(name, "unset", ft_strlen(name)))
		execunset(buff);
	else if (!ft_strncmp(name, "env", ft_strlen(name)))
		execenv(buff);
	else
		execcommand(buff);
}

void	initialise(char	**env, t_nums *nums)
{
	nums->hlogc = 1;
	nums->hfd = 0;
	nums->hyphen = 1;
	setenviron(env, nums);
}

int	main(int argc, char **argv, char **envp)
{
	char	*b;
	t_nums	*nums;

	if (argc != 1 || argv[1])
		return (1);
	nums = malloc(sizeof(t_nums));
	initialise(envp, nums);
	signal(SIGINT, dhandler);
	signal(SIGQUIT, dhandler);
	while (1)
	{
		b = readline("Mike's minishell % ");
		if (b)
		{
			loghistory(b, nums);
			initparse(b, nums);
			free(b);
		}
		if (!b)
		{
			freeenvnstruct(nums);
			return (0);
		}
	}
}
