/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/25 15:43:49 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	setenviron();
}

int	main(void)
{
	char	*b;
	char	*buff;
	t_nums	*nums;
	int		sigx;

	nums = malloc(sizeof(t_nums));
	initialise(nums);
	while (1)
	{
		sigx = sighandler();
		b = readline("Mike's minishell % ");
		if (b)
		{
			buff = ft_strdup(exportout(b));
			loghistory(buff, nums);
			parseargs(buff);
			free(buff);
		}
		if (!b)
		{
			free(nums);
			free(g_env);
			return (0);
		}
	}
}
