/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:31:27 by antimit           #+#    #+#             */
/*   Updated: 2024/10/22 16:43:00 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int num)
{
	long	nlong;
	int		count;
	char	c;

	count = 0;
	nlong = num;
	if (nlong < 0)
	{
		count += write(1, "-", 1);
		nlong = -nlong;
	}
	if (nlong >= 10)
	{
		count += print_nbr(nlong / 10);
	}
	c = nlong % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

int	unsigned_print_nbr(unsigned int num)
{
	int		count;
	char	c;

	count = 0;
	if (num >= 10)
	{
		count += unsigned_print_nbr(num / 10);
	}
	c = num % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}
