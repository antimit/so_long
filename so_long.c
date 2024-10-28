/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:29:12 by onosul            #+#    #+#             */
/*   Updated: 2024/10/28 12:29:14 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	check_arguments(argc, argv, game);
	init_map(game, argv[1]);
	init_vars(game);
	check_map(game);
	init_mlx(game);
	init_sprite(game);
	ft_render_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, close_game, game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, ft_render_map, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
