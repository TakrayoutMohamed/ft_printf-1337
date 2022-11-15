/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:08:38 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/16 00:28:37 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			chars_count;
	va_list		ptr;
	void		*va_arg;

	chars_count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str != '%')
			caseof_xs_d_i_c(*str, &chars_count, 'c');
		else
		{
			str++;
			if (*str == '\0')
				return (chars_count);
			if (*str != '%')
				va_arg = va_arg(ptr, void *);
			print(va_arg, &chars_count, *str);
		}
		str++;
	}
	return (chars_count);
}
