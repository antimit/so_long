# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onosul <onosul@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 11:21:46 by onosul            #+#    #+#              #
#    Updated: 2024/10/27 11:21:50 by onosul           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libgnl.a
HEADER_FILE = get_next_line.h
FILES = get_next_line.c\
	get_next_line_utils.c

CFLAGS = -Wextra -Wall -Werror -fPIC
OFILES = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

%.o: %.c $(HEADER_FILE)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
