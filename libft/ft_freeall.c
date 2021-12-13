/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/12/13 14:47:58 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

static size_t	numlen(void *p)
{
	size_t	i;
	long	l;

	i = 1;
	l = (long)p;
	while (l)
	{
		i++;
		l /= 10;
	}
	return (i);
}

void	ft_freeall(void	*p, ...)
{
	va_list	args;
	void	*pt;

	va_start(args, p);
	pt = va_arg(args, void *);
	free(p);
	while ((numlen(pt)) >= 8)
	{
		free(pt);
		pt = va_arg(args, void *);
	}
	va_end(args);
}

/*int main()
{
	char *s,*c;

	s = malloc(1); c = malloc(1);;
	ft_freeall(s, c);
}*/
