/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:36 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/15 22:45:35 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*returns the len of a number*/
int	ft_numberlen(long int nbr)
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

/*returns the len of an unsigned number*/
int	ft_unumberlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*convert a number to hexadecimal with the interval of UINT*/
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

/*convert a number to hexadecimal with the interval of ULONG*/
void	ft_nbrhexa_p(unsigned long nbr, int *countchars)
{
	char	hexnum;

	hexnum = "0123456789abcdef"[nbr % 16];
	if (nbr >= 0 && nbr < 16)
	{
		ft_putchar_fd(hexnum, 1);
		*countchars = *countchars + 1;
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_fd(nbr *= -1, 1);
	}
	else
	{
		ft_nbrhexa_p(nbr / 16, countchars);
		ft_nbrhexa_p(nbr % 16, countchars);
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
