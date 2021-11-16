/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/16 14:29:19 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parseargs(char *b)
{
	if (!ft_strncmp(b, "ls", 2))
		execls(b);
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
