/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:22:22 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 11:22:24 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*p;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(size + 1);
	if (!p)
	{
		return (NULL);
	}
	i = 0;
	while (i < ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		p[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	p[ft_strlen(s1) + i] = '\0';
	return (p);
}
