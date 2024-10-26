/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:18:40 by antimit           #+#    #+#             */
/*   Updated: 2024/10/26 18:18:42 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_srpite(game, x, y);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_identify_srpite(t_game *game, int x, int y)
{
	if (game->map.full[y][x] == FLOOR)
		ft_render_sprite(game, game->floor, y, x);
	if (game->map.full[y][x] == WALL)
		ft_render_sprite(game, game->wall, y, x);
	if (game->map.full[y][x] == COINS)
		ft_render_sprite(game, game->coins, y, x);
	if (game->map.full[y][x] == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite(game, game->open_exit, y, x);
		else
			ft_render_sprite(game, game->exit_closed, y, x);
	}
	if (game->map.full[y][x] == PLAYER)
	{
		ft_render_player(game, y, x);
	}
}

void	ft_render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
	{
		ft_render_sprite(game, game->player_front, y, x);
	}
	else if (game->player_sprite == BACK)
	{
		ft_render_sprite(game, game->player_back, y, x);
	}
	if (game->player_sprite == RIGHT)
	{
		ft_render_sprite(game, game->player_right, y, x);
	}
	if (game->player_sprite == LEFT)
	{
		ft_render_sprite(game, game->player_left, y, x);
	}
}

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 0xFFF5E1, phrase);
	free(movements);
	free(phrase);
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr,
		sprite.x * column, sprite.y * line);
}
