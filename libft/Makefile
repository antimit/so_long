# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onosul <onosul@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 12:27:38 by onosul            #+#    #+#              #
#    Updated: 2024/10/28 12:27:41 by onosul           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




NAME =  libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_strnstr.c \
		ft_strlen.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_double_strdup.c\
		ft_itoa.c\
		ft_isletter.c\
		ft_strncmp.c
OBJS = $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -I. -c -o $@ $<

all:$(NAME)

$(NAME):$(OBJS)
	ar rcs $@ $^

clean: 
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

.PHONY: all clean fclean




