/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_coin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:29:24 by onosul            #+#    #+#             */
/*   Updated: 2024/10/28 12:29:26 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_coin(t_game *game)
{
	char	**tab;

	tab = ft_custom_double_strdup(game->map.full);
	mark_unreachable_positions(game, tab);
	check_coin_accessibility(game, tab);
	ft_free_tab(tab);
}

void	check_coin_accessibility(t_game *game, char **tab)
{
	int	i;

	i = 0;
	while (i < game->map.coins)
	{
		if (tab[game->map.coins_pos[i].y][game->map.coins_pos[i].x] != 'F')
		{
			ft_free_tab(tab);
			free(game->map.coins_pos);
			ft_error_message(game, "Coin is behind exit");
		}
		i++;
	}
	free(game->map.coins_pos);
}

void	mark_unreachable_positions(t_game *game, char **tab)
{
	int	i;

	i = 0;
	tab[game->map.player.y][game->map.player.x] = '0';
	while (i < game->map.coins)
	{
		tab[game->map.coins_pos[i].y][game->map.coins_pos[i].x] = '0';
		i++;
	}
	fill(tab, (t_positon){game->map.columns, game->map.rows},
		(t_positon){game->map.player.x, game->map.player.y}, '0');
}

void	initialize_map_and_coins(t_game *game, char ***tab)
{
	*tab = ft_custom_double_strdup(game->map.full);
	(*tab)[game->map.player.y][game->map.player.x] = '0';
	(*tab)[game->map.exit_t.y][game->map.exit_t.x] = '0';
	game->map.coins_pos = (t_positon *)malloc(game->map.coins
			* sizeof(t_positon));
	if (!game->map.coins_pos)
	{
		ft_free_tab(*tab);
		ft_error_message(game, "Didn't allocate");
	}
}
