/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:22:53 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 14:22:03 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.full[0][i])
	{
		if (game->map.full[0][i] != '1')
		{
			ft_error_message(game,
				"The map  has a space in a wall at the front row");
		}
		i++;
	}
	i = 0;
	while (game->map.full[game->map.rows - 1][i])
	{
		if (game->map.full[game->map.rows - 1][i] != '1')
		{
			ft_error_message(game,
				"The map has a space in a wall at the back row");
		}
		i++;
	}
}

void	check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != '1')
		{
			ft_error_message(game,
				"The map  has a space in a wall at the front column");
		}
		i++;
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][game->map.columns - 1] != '1')
		{
			ft_error_message(game,
				"The map has a space in a wall at the back column");
		}
		i++;
	}
}

void	check_rectengular_form(t_game *game)
{
	int	len;
	int	i;
	int	len1;

	len = ft_strlen(game->map.full[0]);
	i = 1;
	while (game->map.full[i])
	{
		len1 = ft_strlen(game->map.full[i]);
		if (len != len1)
		{
			ft_error_message(game, "the map is not rectengular");
		}
		i++;
	}
}

void	valid_path(t_game *game)
{
	char	**tab;
	char **tab1;
	int		i;
	int		j;
	int		k;
	// int		a;

	tab = ft_custom_double_strdup(game->map.full);
	tab1 = ft_custom_double_strdup(game->map.full);
	tab[game->map.player.y][game->map.player.x] = '0';
	tab[game->map.exit_t.y][game->map.exit_t.x] = '0';
	tab1[game->map.player.y][game->map.player.x] = '0';
	tab1[game->map.exit_t.y][game->map.exit_t.x] = '0';
	
	fill(tab, (t_positon){game->map.columns, game->map.rows},
		(t_positon){game->map.player.x, game->map.player.y}, '0');
	if (tab[game->map.exit_t.y][game->map.exit_t.x] != 'F')
	{
		ft_free_tab(tab);
		ft_free_tab(tab1);
		ft_error_message(game, "Exit is inaccessible");
	}
	game->map.coins_pos = (t_positon *)malloc(game->map.coins);
	if(!game->map.coins_pos)
	{
		ft_free_tab(tab);
		ft_free_tab(tab1);
		ft_error_message(game, "Didn't allocate");	
	}
	k = 0;
	i = 0;
	while (tab1[i])
	{
		j = 0;
		while (tab1[i][j])
		{
			if (tab1[i][j] == 'C')
			{
				game->map.coins_pos[k] = (t_positon){j, i};
				
				k++;
			}
			j++;
		}
		i++;
	}
	// a = 0;
	// while (a < game->map.coins)
	// {
	// 	if (tab[game->map.coins_pos[a].y][game->map.coins_pos[a].x] != 'F')
	// 	{
	// 		ft_free_tab(tab);
	// 		ft_free_tab(tab1);
	// 		free(game->map.coins_pos);
	// 		ft_error_message(game, "Exit is inaccessible");
	// 	}
	// 	a++;
	// }
	free(game->map.coins_pos);
	ft_free_tab(tab);
}

void	check_map(t_game *game)
{
	check_rectengular_form(game);
	check_columns(game);
	check_rows(game);
	count_parameters(game);
	verify_parameters(game);
	check_rectengular_form(game);
	valid_path(game);
}
