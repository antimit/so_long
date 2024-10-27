


NAME = so_long
LFLAGS = -L./ft_printf -lftprintf -L./get_next_line -lgnl -L./libft -lft

SRCS = so_long.c check_arguments.c init_map.c check_map.c init_game.c render_map.c handle_input.c free_memory.c check_parameter.c validate_path.c


OBJS = $(SRCS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror -g  -I/usr/include -Imlx_linux -O3 


MLX_LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 


$(NAME): $(OBJS)
	make -C libft
	make -C get_next_line
	make -C ft_printf
	$(CC)  $(OBJS) $(MLX_LIB)  $(LFLAGS) -o $(NAME) -lmlx -lX11 -lXext -lm


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	make clean -C libft
	make clean -C get_next_line
	make clean -C ft_printf


fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C get_next_line
	make fclean -C ft_printf



re: fclean $(NAME)



