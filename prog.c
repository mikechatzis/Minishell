/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:44:37 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/31 15:16:37 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\b\b  ", 4);
		write(2, "\nMike's minishell % ", 20);
	}
	else if (signum == SIGQUIT)
		return ;
}

int	main(int argc, char **argv)
{
	char	*c;

	signal(SIGINT, handler);
	c = readline("promt>");
	if (c == 0)
		return (0);
	if (argv[1])
		printf("test successful with args\n");
	else
		printf("test successful without args\n");
	return (0);
}
