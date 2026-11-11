/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fercarva <fercarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:42:37 by fercarva          #+#    #+#             */
/*   Updated: 2026/11/11 18:13:17 by fercarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	validate_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count += print_char('%');
	else if (c == 'c')
		count += print_char(va_arg(args, int));
	else if (c == 's')
		count += print_string(va_arg(args, char *));
	else if (c == 'p')
		count += print_ptr(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		count += print_nbr(va_arg(args, int));
	else if (c == 'u')
		count += print_unsign(va_arg(args, unsigned int));
	else if (c == 'x')
		count += print_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += validate_format(format[i + 1], args);
			i += 2;
		}
		else
		{
			count += print_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
