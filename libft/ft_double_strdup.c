/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:21:55 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 11:21:56 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_memory(char **str, int pos)
{
	while (--pos >= 0)
	{
		if (str[pos])
			free(str[pos]);
	}
	free(str);
}

char	**ft_custom_double_strdup(char **str)
{
	int		count;
	char	**result;

	if (!str || !*str)
		return (NULL);
	count = 0;
	while (str[count])
		count++;
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	count = 0;
	while (str[count])
	{
		result[count] = ft_custom_strdup(str[count]);
		if (!result[count])
		{
			free_memory(result, count);
			return (NULL);
		}
		count++;
	}
	result[count] = NULL;
	return (result);
}
