/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/16 11:32:37 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"
# include <readline/readline.h>
# include <readline/history.h>

int	main(int argc, char **argv)
{
	char	*b;
	while (1)
	{
		b = ft_strdup("hello world");
		if (b && argc && argv)
		{
			printf("test success");
			free(b);
			return (0);
		}
	}
}
