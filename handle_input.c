/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:18:19 by antimit           #+#    #+#             */
/*   Updated: 2024/10/26 19:41:09 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keycode, t_game *game)
{
	if (keycode == W || keycode == KEYUP)
	{
		move_player(game->map.player.x, game->map.player.y - 1, BACK, game);
	}
	if (keycode == S || keycode == KEYDOWN)
	{
		move_player(game->map.player.x, game->map.player.y + 1, FRONT, game);
	}
	if (keycode == D || keycode == KEYRIGHT)
	{
		move_player(game->map.player.x + 1, game->map.player.y, RIGHT, game);
	}
	if (keycode == A || keycode == KEYLEFT)
	{
		move_player(game->map.player.x - 1, game->map.player.y, LEFT, game);
	}
	if (keycode == Q || keycode == ESC)
	{
		close_game(game);
	}
	ft_render_map(game);
	return (0);
}

void	move_player(int new_x, int new_y, int player_sprite, t_game *game)
{
	int	last_x;
	int	last_y;

	game->player_sprite = player_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if ((game->map.full[new_y][new_x] == FLOOR)
		|| (game->map.full[new_y][new_x] == COINS))
	{
		if (game->map.full[new_y][new_x] == COINS)
			game->map.coins--;
		game->map.full[last_y][last_x] = '0';
		game->map.full[new_y][new_x] = 'P';
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->movements++;
		ft_printf("Number of movements: %d\n", game->movements);
		ft_render_map(game);
	}
	if ((game->map.full[new_y][new_x] == MAP_EXIT && game->map.coins == 0))
	{
		game->movements++;
		ft_printf("Number of movements: %d\n", game->movements);
		close_game(game);
	}
}

int	close_game(t_game *game)
{
	ft_free_all_allocated_memory(game);
	exit(EXIT_FAILURE);
	return (0);
}
