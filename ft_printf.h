/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fercarva <fercarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:03:17 by fercarva          #+#    #+#             */
/*   Updated: 2026/11/11 01:24:49 by fercarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	validate_format(char c, va_list args);
int	print_char(int c);
int	print_string(char *str);
int	print_nbr(int nbr);
int	print_unsign(unsigned int nbr);
int	print_hexa(unsigned long nbr, char *str);
int	print_ptr(void *nbr);

#endif