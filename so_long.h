/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:18:55 by antimit           #+#    #+#             */
/*   Updated: 2024/10/26 18:27:35 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define KEYUP 65362
# define KEYDOWN 65364
# define KEYRIGHT 65363
# define KEYLEFT 65361

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define Q 113

# define FRONT 1
# define LEFT 2
# define RIGHT 3
# define BACK 4

# define IMG_HEIGHT 64
# define IMG_WIDTH 64

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

# define WALL_XPM "sprites/wall.xpm"
# define FLOOR_XPM "sprites/floor.xpm"
# define COINS_XPM "sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM "sprites/player/front.xpm"
# define PLAYER_LEFT_XPM "sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM "sprites/player/right.xpm"
# define PLAYER_BACK_XPM "sprites/player/back.xpm"
# define OPEN_EXIT_XPM "sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM "sprites/exit-closed.xpm"

typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_position
{
	int			x;
	int			y;
}				t_positon;

typedef struct s_image
{
	void		*xpm_ptr;
	int			x;
	int			y;
}				t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
	t_positon	exit_t;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}				t_game;


//Check arguments 
void	ft_error_message(t_game *game, char *message);
void	check_arguments(int argc, char *argv[], t_game *game);



//Check map
void	check_rows(t_game *game);
void	check_columns(t_game *game);
void	check_rectengular_form(t_game *game);
void	valid_path(t_game *game);
void	check_map(t_game *game);


//Check parameters
void	recognize_parameter(t_game *game, int i, int j);
void	count_parameters(t_game *game);
void	verify_parameters(t_game *game);
void	fill(char **tab, t_positon size, t_positon cur, char to_fill);


//Free memory 
void	destroy_images(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_tab(char **tab);


//Handle input
int	handle_input(int keycode, t_game *game);
void	move_player(int new_x, int new_y, int player_sprite, t_game *game);
int	close_game(t_game *game);

//init_game 
void	init_mlx(t_game *game);
t_image	new_sprite(void *mlx, char *path, t_game *game);
void	init_sprite(t_game *game);


//init_map
char	*ft_append_string(char *left_str, char *buff);
void	init_map(t_game *game, char *argv);
void	ft_check_for_empty_line(t_game *game, char *map);
void	init_vars(t_game *game);

//Render map
int	ft_render_map(t_game *game);
void	ft_identify_srpite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int y, int x);
void	ft_print_movements(t_game *game);
void	ft_render_sprite(t_game *game, t_image sprite, int line, int column);


//So long

#endif