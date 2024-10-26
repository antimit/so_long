/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:18:34 by antimit           #+#    #+#             */
/*   Updated: 2024/10/26 18:47:31 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_append_string(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((str_len(left_str) + str_len(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[str_len(left_str) + str_len(buff)] = '\0';
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
		ft_error_message(game, "The newline was detected at the beginning");
		free(map);
	}
	if (map[ft_strlen(map) - 1] == '\n')
	{
		ft_error_message(game, "The newline was detected at the end");
		free(map);
	}
	i = 0;
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			ft_error_message(game, "The newline was detected in the middle");
			free(map);
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
	game->map_alloc = false;
	game->player_sprite = RIGHT;
}