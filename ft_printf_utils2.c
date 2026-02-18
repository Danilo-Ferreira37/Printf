/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:16:06 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/19 17:21:35 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hexa(t_ull adr, unsigned int base_len, char *base)
{
	int	counter;

	counter = 0;
	if (adr >= base_len)
		counter += print_hexa(adr / base_len, base_len, base);
	counter += ft_putchar(base[adr % base_len]);
	return (counter);
}

int	ft_print_adress(void *adrs, unsigned int base_len, char *base)
{
	int		counter;
	t_ull	adr;

	if (adrs == NULL || adrs < 0)
		return (write(1, "(nil)", 5));
	adr = (t_ull)adrs;
	write(1, "0x", 2);
	counter = 2;
	counter += print_hexa(adr, base_len, base);
	return (counter);
}

int	ft_base(unsigned int n, unsigned int base_len, char *base)
{
	int	counter;

	counter = 0;
	if (n >= base_len)
		counter += ft_base(n / base_len, base_len, base);
	counter += ft_putchar(base[n % base_len]);
	return (counter);
}
