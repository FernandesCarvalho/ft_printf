/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fercarva <fercarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 00:24:49 by fercarva          #+#    #+#             */
/*   Updated: 2026/11/11 18:09:20 by fercarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += print_char(*str);
		str++;
	}
	return (count);
}

int	print_nbr(int nbr)
{
	long	nb;
	int		count;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb > 9)
		count += print_nbr(nb / 10);
	count += print_char((nb % 10) + '0');
	return (count);
}

int	print_unsign(unsigned int nbr)
{
	unsigned int	nb;
	int				count;

	nb = nbr;
	count = 0;
	if (nb > 9)
		count += print_unsign(nb / 10);
	count += print_char((nb % 10) + '0');
	return (count);
}

int	print_hexa(unsigned long nbr, char *str)
{
	unsigned long	nb;
	int				count;

	nb = nbr;
	count = 0;
	if (nb > 15)
		count += print_hexa((nb / 16), str);
	count += print_char(str[nb % 16]);
	return (count);
}

int	print_ptr(void *nbr)
{
	unsigned long	nb;
	int				count;

	nb = (unsigned long)nbr;
	count = 0;
	if (!nb)
		return (print_string("(nil)"));
	count += print_string("0x");
	count += print_hexa(nb, "0123456789abcdef");
	return (count);
}
