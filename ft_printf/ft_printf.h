/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:20:52 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 11:20:53 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	print_hexadecimal(char character, unsigned int num);
int	print_hex_digit(unsigned char digit);
int	print_address(void *ptr);
int	print_char(int c);
int	print_str(char *str);
int	print_nbr(int num);
int	unsigned_print_nbr(unsigned int num);
int	print_format(char character, va_list ap);
int	ft_printf(const char *format, ...);

#endif
