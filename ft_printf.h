/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:10:24 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/15 22:45:24 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft_utils/libft.h"

int		ft_printf(const char *c, ...);
/*utils functions*/
int		ft_numberlen(long int nbr);
int		ft_unumberlen(unsigned int nbr);
void	ft_nbrhexa(unsigned int nbr, int *countchars, char type);
void	ft_nbrhexa_p(unsigned long nbr, int *countchars);
void	ft_putunbr_fd(unsigned int n, int fd);
/*function from the file print.c*/
void	caseof_s(char *str, int *increase);
void	caseof_xs_d_i_c(int nbr, int *increase, char type);
void	caseof_p(unsigned long ulnbr, int *increase);
void	caseof_u(unsigned int unbr, int *increase);
void	print(unsigned char *va_arg, int *chars_count, char c);
#endif
