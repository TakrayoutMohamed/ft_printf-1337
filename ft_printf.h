/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:10:24 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/15 05:59:07 by mohtakra         ###   ########.fr       */
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
int		ft_numberlen(int nbr);
int		ft_unumberlen(unsigned int nbr);
void	ft_nbrhexa(unsigned int nbr, int *countchars, char type);
void	ft_putunbr_fd(unsigned int n, int fd);
#endif
