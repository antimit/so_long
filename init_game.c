/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:23:18 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 23:01:07 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		ft_error_message(game, "The mlx pointer was not correctly assigned");
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "So_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		ft_error_message(game, "Couldn't load the window");
	}
}

t_image	new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (!sprite.xpm_ptr)
	{
		ft_error_message(game, "Couldn't create a sprite");
	}
	return (sprite);
}

void	init_sprite(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	mlx = game->mlx_ptr;
	game->wall = new_sprite(mlx, WALL_XPM, game);
	game->floor = new_sprite(mlx, FLOOR_XPM, game);
	game->coins = new_sprite(mlx, COINS_XPM, game);
	game->player_front = new_sprite(mlx, PLAYER_FRONT_XPM, game);
	game->player_left = new_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = new_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->player_back = new_sprite(mlx, PLAYER_BACK_XPM, game);
	game->open_exit = new_sprite(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = new_sprite(mlx, EXIT_CLOSED_XPM, game);
}
