/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fercarva <fercarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:42:37 by fercarva          #+#    #+#             */
/*   Updated: 2026/11/09 18:46:34 by fercarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char(int c)
{
	return (write(1, &c, 1));
}

static int	validate_format(int c, va_list args)
{
	
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
