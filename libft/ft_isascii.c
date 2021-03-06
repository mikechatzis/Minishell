/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:41:07 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/21 17:28:00 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if ((c > 0 && c <= 127))
		return (c);
	else if (c == 0)
		return (c + 1);
	else
		return (0);
}
