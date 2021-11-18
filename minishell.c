/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/18 15:06:40 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parseargs(char *b)
{
	int	l;
	int	i;

	l = ft_strlen(b);
	i = -1;
	if (!ft_strncmp(b, "ls", 2))
		execls(b);
	else if (!ft_strncmp(b, "pwd", l))
		execpwd();
	else if (!ft_strncmp(b, "cd", 2))
		execcd(b);
	else if (!ft_strncmp(b, "./", 2))
		execprog(b);
	else
	{
		while (b[++i] != ' ' && b[i])
			write(2, &b[i], 1);
		write(2, ": command not found\n", 20);
	}
}

void	initialise(t_nums *nums)
{
	nums->hlogc = 1;
	nums->hfd = 0;
	g_path = getcwd(g_path, 100);
}

int	main(void)
{
	char	*b;
	t_nums	*nums;

	nums = malloc(sizeof(t_nums));
	initialise(nums);
	while (1)
	{
		printf("Mike's minishell %% ");
		b = readline(NULL);
		if (b)
		{
			loghistory(b, nums);
			parseargs(b);
			free(b);
		}
	}
}
