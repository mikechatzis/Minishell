/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2021/11/18 14:44:54 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

void	ft_freeall(void	*p, ...)
{
	va_list	args;
	void	*pt;

	va_start(args, p);
	pt = malloc(1);
	free(p);
	while (pt)
	{
		free(pt);
		pt = va_arg(args, void *);
	}
}

/*int main()
{
	char *s,*c,*k;

	s = malloc(1); c = malloc(1); k = malloc(1);
	ft_freeall(s, c, k);
	printf("%p %p %p\n", s, c, k);
}*/
