/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:22:15 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 11:22:16 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_custom_strdup(const char *s)
{
	size_t	len;
	char	*result;
	int		i;

	if (!s)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
