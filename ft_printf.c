/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:08:38 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/14 03:52:37 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_printf(const char *str, ...)
{
	int					chars_count;
	va_list				ptr;
	char				*helper_str;
	int					helper_nbr;
	unsigned int		helper_unbr;

	chars_count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd((char)str, 1);
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
			else if (*str == 's' || *str == 'c')
			{
				helper_str = va_arg(ptr, char *);
				ft_putstr_fd(helper_str, 1);
				chars_count += ft_strlen(helper_str);
			}
			else if (*str == 'd' || *str == 'i')
			{
				helper_nbr = va_arg(ptr, int);
				chars_count += ft_numberlen(helper_nbr);
				ft_putnbr_fd(helper_nbr, 1);
			}
			else if (*str == 'X' || *str == 'x' || *str == 'p')
			{
				if (*str == 'p')
					ft_putstr_fd("0x",1);
				ft_nbrhexa(va_arg(ptr, int), &chars_count, *str);
			}
			else if (*str == 'u')
			{
				helper_nbr = va_arg(ptr, unsigned int);
				ft_putnbr_fd(helper_nbr, 1);
				chars_count += ft_numberlen(helper_nbr);
			}
		}
		str++;
	}
	
	return (chars_count);
}
