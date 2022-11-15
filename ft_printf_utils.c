/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:36 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/15 06:06:12 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*return how many number in an unsigned number*/
int	ft_unumberlen(unsigned int nbr)
{
	int	len;

	len = 0;
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

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
}
