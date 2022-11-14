/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:36 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/14 20:30:42 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
/*return how many number in a number*/
int	ft_numberlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*convert a number to hexadecimal*/
void	ft_nbrhexa(unsigned int nbr, int *countchars, char type)
{
	char	hexnum;

	if (type == 'x' || type == 'p')
		hexnum = "0123456789abcdef"[nbr % 16];
	else if (type == 'X')
		hexnum = "0123456789ABCDEF"[nbr % 16];
	if (nbr >= 0 && nbr < 16)
	{
		ft_putchar_fd(hexnum, 1);
		*countchars = *countchars + 1;
	}
	else
	{
		ft_nbrhexa(nbr / 16, countchars, type);
		ft_nbrhexa(nbr % 16, countchars, type);
	}
}
