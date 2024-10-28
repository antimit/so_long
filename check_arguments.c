/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:27:48 by onosul            #+#    #+#             */
/*   Updated: 2024/10/28 12:27:49 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(t_game *game, char *message)
{
	if (game->map_alloc == true)
	{
		ft_free_map(game);
	}
	free(game);
	ft_printf("Error\n %s\n", message);
	exit(EXIT_FAILURE);
}

void	check_arguments(int argc, char *argv[], t_game *game)
{
	int	len;

	game->map_alloc = false;
	if (argc > 2)
	{
		ft_error_message(game, "Too many arguments were given");
	}
	else if (argc < 2)
	{
		ft_error_message(game, "The map is missing");
		return ;
	}
	len = ft_strlen(argv[1]);
	if (len < 5 || argv[1][0] == '.' || argv[1][len - 4] != '.'
		|| ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
	{
		ft_error_message(game, "Wrong file or bad extension");
	}
	else if (argv[1][len - 5] == '/')
	{
		ft_error_message(game, "Wrong file or bad extension");
	}
}
