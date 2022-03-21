/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:40:33 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/21 17:52:24 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	writer_handle(char	*eof, t_parameters *params)
{
	char	*line[2048];
	int		i;

	i = 0;
	params->fd_io[0] = open(" ", O_RDWR | O_CREAT, 0644);
	if (params->fd_io[0] == -1)
		open_failed(params);
	while (gnl(STDIN_FILENO, line) != 0
		&& ft_strncmp(*line, eof, ft_strlen(eof)) != 0)
	{
		if (write(params->fd_io[0], *line, ft_strlen(*line)) == -1)
			return (write_failed(params, *line));
		if (write(params->fd_io[0], "\n", 1) == -1)
			return (write_failed(params, *line));
		free (*line);
		if (++i == 2048)
		{
			printf("the number of new lines reached 2048 limit, stopping\n");
			return ;
		}
	}
	free (*line);
}
