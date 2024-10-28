/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:22:39 by onosul            #+#    #+#             */
/*   Updated: 2024/10/28 10:26:48 by antimit          ###   ########.fr       */
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
int is_letter(char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
