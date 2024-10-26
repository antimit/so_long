# NAME = so_long
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3

# LFLAGS = -L./ft_printf -lftprintf -L./get_next_line -lgnl -L./libft -lft

# SRCS = so_long.c check_arguments.c init_map.c check_map.c init_game.c

# MLX_LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


# OBJS = $(SRCS:.c=.o)

# %.o:%.c
# 	$(CC) $(CFLAGS)  $(LFLAGS) -I.  -c -o $@ $^

# all:$(NAME)


# $(NAME):$(OBJS)
# 	$(CC)  $(MLX_LIB) -o $@ $^ $(LFLAGS)

# clean:
# 	rm -rf $(OBJS)

# fclean: clean
# 	rm -rf  $(NAME)

# .PHONY: all clean fclean 

NAME = so_long
LFLAGS = -L./ft_printf -lftprintf -L./get_next_line -lgnl -L./libft -lft
# Source files
SRCS = so_long.c check_arguments.c init_map.c check_map.c init_game.c render_map.c handle_input.c free_memory.c check_parameter.c

# Object files generated from source files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g  -I/usr/include -Imlx_linux -O3 

# Library flags for MiniLibX and X11
MLX_LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

# Build the final executable from object files
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_LIB)  $(LFLAGS) -o $(NAME) -lmlx -lX11 -lXext -lm

# Rule for compiling .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the final executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean $(NAME)



