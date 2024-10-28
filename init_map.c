/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:28:28 by onosul            #+#    #+#             */
/*   Updated: 2024/10/28 12:28:41 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_init_left_str(char *left_str)
{
	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	return (left_str);
}

char	*ft_append_string(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	left_str = ft_init_left_str(left_str);
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (str_len(left_str) + str_len(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (left_str[++i] != '\0')
		str[i] = left_str[i];
	j = 0;
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}

void	init_map(t_game *game, char *argv)
{
	char	*line_temp;
	char	*map_temp;
	int		fd;

	game->map.rows = 0;
	map_temp = NULL;
	fd = open(argv, O_RDWR);
	if (fd == -1)
	{
		ft_error_message(game, "Couldn't read from the file");
	}
	while (1)
	{
		line_temp = get_next_line(fd);
		if (!line_temp)
			break ;
		map_temp = ft_append_string(map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(fd);
	ft_check_for_empty_line(game, map_temp);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

void	ft_check_for_empty_line(t_game *game, char *map)
{
	size_t	i;

	if (!map)
		ft_error_message(game, "The map is empty");
	if (map[0] == '\n')
	{
		free(map);
		ft_error_message(game, "The newline was detected at the beginning");
	}
	if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error_message(game, "The newline was detected at the end");
	}
	i = 0;
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_message(game, "The newline was detected in the middle");
		}
		i++;
	}
}

void	init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->player_sprite = RIGHT;
}
