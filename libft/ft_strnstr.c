/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:01:51 by antimit           #+#    #+#             */
/*   Updated: 2024/10/26 18:01:52 by antimit          ###   ########.fr       */
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
