/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/03/11 11:08:45 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loghistory(char *b, t_nums *nums)
{
	char	*s;

	if (!*b || !b)
		return ;
	add_history(b);
	if (!nums->hfd)
		nums->hfd = open("history", O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (nums->hfd <= 0)
	{
		perror("open");
		return ;
	}
	s = ft_itoa(nums->hlogc);
	if ((write(nums->hfd, s, ft_strlen(s))) == -1)
		perror("write");
	write(nums->hfd, " ", 1);
	write(nums->hfd, b, ft_strlen(b));
	write(nums->hfd, "\n", 1);
	free(s);
	nums->hlogc++;
}
