/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/25 16:33:20 by mchatzip         ###   ########.fr       */
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
		if (!b)
		{
			free(nums);
			return(0);
		}
		bslashhandler();
	}
}
