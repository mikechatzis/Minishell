/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/28 17:15:28 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

void	ft_freeall(size_t ptrnum, void	*p, ...)
{
	va_list	args;
	void	*pt;
	size_t	i;

	i = 0;
	va_start(args, p);
	pt = va_arg(args, void *);
	free(p);
	while (i++ < ptrnum)
	{
		free(pt);
		pt = va_arg(args, void *);
	}
	va_end(args);
}

// int main()
// {
// 	char *s,*c, *k, *j;

// 	s = malloc(1); c = malloc(1); k = malloc(1); j = malloc(1);
// 	ft_freeall(3, s, c, k, j);
// }
