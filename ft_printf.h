/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:20:58 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/19 18:00:57 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned long long	t_ull;

int							ft_printf(const char *s, ...);
int							ft_putchar(char c);
int							ft_putstr(char *s);
int							ft_putnbr(int nbr);
int							ft_base(unsigned int n, unsigned int base,
								char *symbols);
int							ft_print_adress(void *adrs, unsigned int base_len,
								char *base);

#endif