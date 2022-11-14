/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:10:24 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/14 20:28:59 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./../Libft-42/libft.h"

int		ft_printf(const char *c, ...);
/*utils functions*/
int		ft_numberlen(int nbr);
void	ft_nbrhexa(unsigned int nbr, int *countchars, char type);
#endif
