/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:35:10 by onosul            #+#    #+#             */
/*   Updated: 2024/10/26 18:02:38 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **split, size_t i)
{
	while (i > 0)
	{
		free(split[i - 1]);
		i--;
	}
	free(split);
}

int	skip_chars(const char *str, int i, char sep, int mode)
{
	if (mode == 0)
		while (str[i] && str[i] == sep)
			i++;
	else
		while (str[i] && str[i] != sep)
			i++;
	return (i);
}

size_t	count_words(const char *str, char sep)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		i = skip_chars(str, i, sep, 0);
		if (str[i] && str[i] != sep)
			count++;
		i = skip_chars(str, i, sep, 1);
	}
	return (count);
}

char	*ft_word(const char *str, char sep)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	i;
	int		start;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[start])
	{
		start = skip_chars(s, start, c, 0);
		if (s[start] && s[start] != c)
		{
			result[i] = ft_word(s + start, c);
			if (!result[i])
				return (free_split(result, i), NULL);
			i++;
		}
		start = skip_chars(s, start, c, 1);
	}
	result[i] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	**result;
// 	char	sep;
// 	char	*str;
// 	int		i;

// 	sep = ',';
// 	str = "Hello,World HI";
// 	result = ft_split(str, sep);
// 	i = 0;
// 	while (i < count_words(str, sep))
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	// printf("%s",result[0]);
// 	return (0);
// }