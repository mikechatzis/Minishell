/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:44:37 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/27 13:45:43 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	c;

	c = getchar();
	if (c == EOF)
		return (0);
	if (argv[1])
		printf("test successful with args\n");
	else
		printf("test successful without args\n");
	return (0);
}
