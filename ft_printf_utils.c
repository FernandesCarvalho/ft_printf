/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fercarva <fercarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 00:24:49 by fercarva          #+#    #+#             */
/*   Updated: 2026/11/10 00:59:41 by fercarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}
int print_string(char *str)
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

int print_nbr(int nbr)
{
	long	nb;
	int		count;

	nb = nbr;
	count = 0;
	if(nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb > 9)
		count += print_nbr(nb / 10);
	count += print_char(nb % 10 + '0');
	return (count);
}