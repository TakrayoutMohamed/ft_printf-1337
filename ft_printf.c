/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:08:38 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/15 19:52:06 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	caseof_s(char *str, int *increase)
{
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	*increase += ft_strlen(str);
}

void	caseof_xs_d_i(int nbr, int *increase, char type)
{
	if (type == 'x' || type == 'X')
		ft_nbrhexa(nbr, increase, type);
	else if (type == 'd' || type == 'i')
	{
		*increase += ft_numberlen(nbr);
		ft_putnbr_fd(nbr, 1);
	}
	else if (type == 'c')
	{
		if (nbr == 0)
			nbr = '\0';
		*increase += 1;
		ft_putchar_fd((char)nbr, 1);
	}
}

void	caseof_p(unsigned long ulnbr, int *increase)
{
	ft_putstr_fd("0x", 1);
	*increase += 2;
	ft_nbrhexa_p(ulnbr, increase);
}
void	caseof_u(unsigned int unbr, int *increase)
{
	ft_putunbr_fd(unbr, 1);
	*increase += ft_unumberlen(unbr);
}

int	ft_printf(const char *str, ...)
{
	int					chars_count;
	va_list				ptr;

	chars_count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd((char)*str, 1);
			chars_count++;
		}
		else
		{
			str++;
			if (*str == '%')
			{
				ft_putchar_fd('%', 1);
				chars_count++;
			}
			else if (*str == 's')
				caseof_s(va_arg(ptr, char *), &chars_count);
			else if (*str == 'X' || *str == 'x' || *str == 'c' || *str == 'd' || *str == 'i')
				caseof_xs_d_i(va_arg(ptr, int), &chars_count, *str);
			else if (*str == 'p')
				caseof_p(va_arg(ptr, unsigned long), &chars_count);
			else if (*str == 'u')
				caseof_u(va_arg(ptr, unsigned int), &chars_count);
		}
		str++;
	}
	return (chars_count);
}
