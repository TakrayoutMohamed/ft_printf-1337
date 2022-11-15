/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:27:14 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/16 00:31:54 by mohtakra         ###   ########.fr       */
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

void	caseof_xs_d_i_c(int nbr, int *increase, char type)
{
	if (type == 'x' || type == 'X')
		ft_nbrhexa(nbr, increase, type);
	else if (type == 'd' || type == 'i')
	{
		*increase += ft_numberlen(nbr);
		ft_putnbr_fd(nbr, 1);
	}
	else if (type == 'c' || type == '%')
	{
		if (nbr == 0)
			nbr = '\0';
		*increase += 1;
		if (type == '%')
			ft_putchar_fd('%', 1);
		else
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

void	print(unsigned char *va_arg, int *chars_count, char c)
{
	if (c == 's')
		caseof_s((char *)va_arg, chars_count);
	else if (ft_strchr("xXdic", c) || c == '%')
		caseof_xs_d_i_c((int)va_arg, chars_count, c);
	else if (c == 'p')
		caseof_p((unsigned long)va_arg, chars_count);
	else if (c == 'u')
		caseof_u((unsigned int)va_arg, chars_count);
}
