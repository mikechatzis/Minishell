/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:48:03 by mchatzip          #+#    #+#             */
/*   Updated: 2021/05/17 11:49:15 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if ((ch >= 97 && ch <= 122))
		return (ch - 32);
	else
		return (ch);
}
