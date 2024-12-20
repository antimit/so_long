/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:21:08 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 11:21:09 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char character, va_list ap)
{
	int	count;

	count = 0;
	if (character == 'c')
		count += print_char(va_arg(ap, int));
	else if (character == 's')
		count += print_str(va_arg(ap, char *));
	else if (character == 'd')
		count += print_nbr(va_arg(ap, int));
	else if (character == 'p')
		count += print_address(va_arg(ap, void *));
	else if (character == 'i')
		count += print_nbr(va_arg(ap, int));
	else if (character == 'u')
		count += unsigned_print_nbr(va_arg(ap, unsigned int));
	else if (character == 'x' || character == 'X')
		count += print_hexadecimal(character, va_arg(ap, unsigned int));
	else
		count += write(1, &character, 1);
	return (count);
}
