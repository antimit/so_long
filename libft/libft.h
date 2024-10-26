/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:01:56 by antimit           #+#    #+#             */
/*   Updated: 2024/10/26 18:01:58 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *s);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_custom_strdup(const char *s);
char	**ft_custom_double_strdup(char **str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

#endif
