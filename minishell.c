/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/22 16:00:39 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dhandler(char *b)
{
	if (b)
		free(b);
	exit(0);
}

void	parseargs(char *b)
{
	int		l;

	l = ft_strlen(b);
	if (!ft_strncmp(b, "ls", 2))
		execls(b);
	else if (!ft_strncmp(b, "pwd", l))
		execpwd();
	else if (!ft_strncmp(b, "cd", 2))
		execcd(b);
	else if (!ft_strncmp(b, "./", 2))
		exec(b);
	else
		ukncommand(b);
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
