/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:03:48 by antimit           #+#    #+#             */
/*   Updated: 2024/10/26 19:41:37 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(t_game *game, char *message)
{
	if (game->map_alloc)
	{
		ft_free_map(game);
	}
	free(game);
	ft_printf("Error\n %s\n", message);
	exit(1);
}

void	check_arguments(int argc, char *argv[], t_game *game)
{
	game->map_alloc = false;
	if (argc > 2)
	{
		ft_error_message(game, "Too many arguments were given");
	}
	else if (argc < 2)
	{
		ft_error_message(game, "The map is missing");
	}
	if (!ft_strnstr((argv[1] + ft_strlen(argv[1]) - 4), ".ber", 4))
	{
		ft_error_message(game, "Wrong file");
	}
}
