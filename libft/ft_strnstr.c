/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:22:34 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 11:22:35 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	if (!little[0])
	{
		return (NULL);
	}
	little_len = ft_strlen(little);
	i = 0;
	while (*big && len >= little_len)
	{
		i = 0;
		while (little[i] && little[i] == big[i])
		{
			i++;
		}
		if (i == little_len)
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}

// int main()
// {
//     char * result = ft_strnstr("Hello World","World",11);
//     printf("%s",result);
// }
