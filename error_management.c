/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:29:19 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:42:40 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	perror(const char *s)
{
	write (2, s, ft_strlen (s));
}

void	end(const char *s)
{
	perror (s);
	exit (EXIT_FAILURE);
}

void	chdir_failed(const char *s)
{
	perror ("error: cd: cannot change directory to ");
	perror (s);
	end ("\n");
}

void	execve_failed(const char *s)
{
	perror ("error: cannot execute ");
	perror (s);
	end ("\n");
}
