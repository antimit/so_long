/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 00:32:21 by antimit           #+#    #+#             */
/*   Updated: 2024/10/28 10:51:24 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_paths(t_game *game, char **tab)
{
	int	a;

	fill(tab, (t_positon){game->map.columns, game->map.rows},
		(t_positon){game->map.player.x, game->map.player.y}, '0');
	if (tab[game->map.exit_t.y][game->map.exit_t.x] != 'F')
	{
		ft_free_tab(tab);
		free(game->map.coins_pos);
		ft_error_message(game, "Exit is inaccessible");
	}
	a = 0;
	while (a < game->map.coins)
	{
		if (tab[game->map.coins_pos[a].y][game->map.coins_pos[a].x] != 'F')
		{
			ft_free_tab(tab);
			free(game->map.coins_pos);
			ft_error_message(game, "Coin is inaccessible");
		}
		a++;
	}
	ft_free_tab(tab);
}

void	locate_coins(t_game *game, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
			{
				game->map.coins_pos[k] = (t_positon){j, i};
				tab[i][j] = '0';
				k++;
			}
			j++;
		}
		i++;
	}
}

void	valid_path(t_game *game)
{
	char	**tab;

	initialize_map_and_coins(game, &tab);
	locate_coins(game, tab);
	validate_paths(game, tab);
	validate_coin(game);
}
