/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:37:40 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/19 22:26:10 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr(int nbr)
{
	long	nb;
	int		count;

	count = 0;
	nb = nbr;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
