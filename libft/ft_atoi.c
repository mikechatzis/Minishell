/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:47:14 by mchatzip          #+#    #+#             */
/*   Updated: 2021/07/08 14:21:52 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = 1 - 2 * (*str++ == '-');
	}
	while (*str >= '0' && *str <= '9')
	{
		if (num > 2147483647 / 10 || (num == 2147483647 / 10 && *str - '0' > 7))
		{
			if (sign == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		num = 10 * num + (*str++ - '0');
	}
	return (num * sign);
}
