/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/27 13:30:03 by mchatzip         ###   ########.fr       */
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

void	parseargs(char *b)
{
	if (!ft_strncmp(b, "ls", 2))
		execls(b);
	else if (!ft_strncmp(b, "pwd", 3))
		execpwd();
	else if (!ft_strncmp(b, "cd", 2))
		execcd(b);
	else if (!ft_strncmp(b, "./", 2))
		exec(b);
	else if (!ft_strncmp(b, "echo", 4))
		exececho(b);
	else if (!ft_strncmp(b, "export", 6))
		execexport(b);
	else if (!ft_strncmp(b, "unset", 5))
		execunset(b);
	else if (!ft_strncmp(b, "env", 3))
		execenv(b);
	else
		ukncommand(b);
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
			initparse(b, nums);
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
