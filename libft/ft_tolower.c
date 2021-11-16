/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:52:16 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/17 11:52:34 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if ((ch >= 65 && ch <= 90))
		return (ch + 32);
	else
		return (ch);
}
