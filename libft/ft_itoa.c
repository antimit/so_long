/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:01:20 by antimit           #+#    #+#             */
/*   Updated: 2024/10/26 18:01:22 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length_int(int n)
{
	int	length;

	if (n > 0)
		length = 0;
	else
		length = 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	num;

	len = length_int(n);
	num = n;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	if (num < 0)
	{
		num = -num;
	}
	result[len] = '\0';
	while (len--)
	{
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
