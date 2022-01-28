/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/28 17:34:33 by mchatzip         ###   ########.fr       */
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
	if (b[i] == '>')
	{
		if (b[i + 1] == '|' || b[i + 1] == '<')
		{
			printf("syntax error close to token: '>'\n");
			return (-1);
		}
		else if (b[i + 1] == '>')
			return (++i);
	}
	if (b[i] == '<')
	{
		if (b[i + 1] == '|' || b[i + 1] == '>')
			printf("syntax error close to token: '<'\n");
		if (b[i + 1] == '|' || b[i + 1] == '>')
			return (-1);
		else if (b[i + 1] == '<')
			return (++i);
	}
	return (i);
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
			ret[j++] = ft_substr(b, 0, i + 1);
			b += i + 1;
			i = -1;
		}
	}
	return (finn(b, ret, j));
}

void	parseargs(char *b, char *buff, char *name)
{
	if (!ft_strncmp(name, "ls", ft_strlen(name)))
		execls(buff);
	else if (!ft_strncmp(name, "pwd", ft_strlen(name)))
		execpwd();
	else if (!ft_strncmp(name, "cd", ft_strlen(name)))
		execcd(buff);
	else if (!ft_strncmp(name, "./", ft_strlen(name)))
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
		ukncommand(buff);
}

void	initialise(t_nums *nums)
{
	nums->hlogc = 1;
	nums->hfd = 0;
	nums->sig = 0;
	setenviron(nums);
}

int	main(void)
{
	char	*b;
	t_nums	*nums;

	nums = malloc(sizeof(t_nums));
	initialise(nums);
	signal(SIGINT, dhandler);
	signal(SIGQUIT, dhandler);
	while (1)
	{
		b = readline("Mike's minishell % ");
		if (b)
		{
			loghistory(b, nums);
			initparse(b);
			free(b);
		}
		if (!b)
		{
			free(nums);
			free(g_env);
			return (0);
		}
	}
}
