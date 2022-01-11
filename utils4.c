/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/11 14:15:17 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setenviron(void)
{
	ENV = malloc(1000 * sizeof(char *));
	ENV[0] = ft_strjoin("PATH=", getenv("PATH"));
	ENV[1] = ft_strjoin("PWD=", getenv("PWD"));
	ENV[2] = ft_strjoin("USER=", getenv("USER"));
	ENV[999] = 0;
}
