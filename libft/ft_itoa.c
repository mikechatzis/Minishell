/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:29:16 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/19 13:19:48 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	calcdig(int const i)
{
	int	k;
	int	l;

	k = 1;
	l = i;
	while (l / 10 != 0)
	{
		l = l / 10;
		k++;
	}
	if (i < 0)
		return (k + 1);
	else
		return (k);
}

char	*ft_itoa(int i)
{
	char	*k;
	int		d;
	long	it;

	it = (long long)i;
	d = calcdig(i);
	k = (char *)malloc(d + 1);
	if (k == NULL)
		return (NULL);
	k[d] = '\0';
	if (it < 0)
	{
		it = -1 * it;
		k[0] = '-';
	}
	while (it / 10 != 0 && d > 0)
	{
		k[d - 1] = it % 10 + 48;
		it = it / 10;
		d--;
	}
	k[d - 1] = it % 10 + 48;
	return (k);
}
