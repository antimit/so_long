/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:22:57 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 11:22:58 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	recognize_parameter(t_game *game, int i, int j)
{
	if (!ft_strchr("PCE10", game->map.full[i][j]))
	{
		ft_error_message(game, "The map contains symbols that are not allowed");
	}
	if (game->map.full[i][j] == 'P')
	{
		game->map.player.x = j;
		game->map.player.y = i;
		game->map.players++;
	}
	else if (game->map.full[i][j] == 'E')
	{
		game->map.exit_t.x = j;
		game->map.exit_t.y = i;
		game->map.exit++;
	}
	else if (game->map.full[i][j] == 'C')
		game->map.coins++;
}

void	count_parameters(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map.full[i])
	{
		j = 0;
		while (game->map.full[i][j])
		{
			recognize_parameter(game, i, j);
			j++;
		}
		i++;
	}
}

void	verify_parameters(t_game *game)
{
	if (game->map.players != 1)
	{
		ft_error_message(game, "The number of players is not 1");
	}
	if (game->map.coins == 0)
	{
		ft_error_message(game, "There is no coin in the map ");
	}
	if (game->map.exit != 1)
	{
		ft_error_message(game, "The number of exits is not 1");
	}
}

void	fill(char **tab, t_positon size, t_positon cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_positon){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_positon){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_positon){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_positon){cur.x, cur.y + 1}, to_fill);
}
