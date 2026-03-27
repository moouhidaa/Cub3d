/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:06:55 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"

int	validate_map(char **map)
{
	if (ft_check_player(map))
	{
		ft_error("Error");
		return (1);
	}
	if (check_closed_map(map))
		return (1);
	return (0);
}

int	nl(int fd, char *line)
{
	while (line != NULL)
	{
		if (onlyw(line))
			return (ft_error("Error"), 1);
		line = get_next_line(fd);
	}
	return (0);
}

int	pars_line(char *line)
{
	int	index_x;

	index_x = 0;
	while (line && line[index_x])
	{
		if (!is_valid_char(line[index_x]))
			return (ft_error("Error"), 1);
		index_x++;
	}
	return (0);
}

int	read_map(int fd, t_hulk *game)
{
	char	*line;

	line = get_next_line(fd);
	game->map->valid_map = NULL;
	while (line)
	{
		if (line[0] != '\n')
		{
			if (pars_line(line))
				return (BAD_M);
			line = ft_strtrim(line, "\r\n");
		}
		if (game->map->valid_map && line && !onlyw(line))
		{
			if (nl(fd, line))
				return (1);
			else
				return (0);
		}
		if (line[0] != '\n')
			game->map->valid_map = my_realloc(game->map->valid_map, line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parse_cub3d(char *filename, t_hulk *game)
{
	game->map = my_malloc(sizeof(t_map));
	if (!game->map)
		return (BAD_M);
	if (read_textures_and_colors(filename, game) || read_map(game->fd, game)
		|| validate_map(game->map->valid_map))
		return (close(game->fd), BAD_M);
	return (GOOD_M);
}
