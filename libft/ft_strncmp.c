/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:27:24 by onosul            #+#    #+#             */
/*   Updated: 2024/10/28 12:27:26 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *s1 && *s2)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			return ((unsigned char)*s1 - ((unsigned char)*s2));
		}
		s1++;
		s2++;
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)*s1 - ((unsigned char)*s2));
	}
	return (0);
}
