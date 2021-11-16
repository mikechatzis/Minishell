/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/16 17:24:50 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parseargs(char *b)
{
	int	l;
	int i;

	l = ft_strlen(b);
	i = -1;
	if (!ft_strncmp(b, "ls", 2))
		execls(b);
	else if (!ft_strncmp(b, "pwd", l))
		execpwd();
	else
	{
		while (b[++i] != ' ' && b[i])
			write(2, &b[i], 1);
		write(2, ": command not found\n", 20);
	}
}

int	main()
{
	char	*b;
	while (1)
	{
		printf("Mike's minishell%% ");
		b = readline(NULL);
		if (b)
		{
			parseargs(b);
			free(b);
		}
	}
}
