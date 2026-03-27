/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:29:28 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 10:11:54 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_colorcf(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_color_paths(char **paths, int i, t_hulk *game)
{
	int	*rgb;

	if (!ft_strncmp(paths[i], "F ", 2))
	{
		rgb = extract_rgb(paths[i]);
		if (!rgb)
			return (ft_error("Error"), 1);
		game->floor = get_colorcf(rgb[0], rgb[1], rgb[2]);
		return (0);
	}
	if (!ft_strncmp(paths[i], "C ", 2))
	{
		rgb = extract_rgb(paths[i]);
		if (!rgb)
			return (ft_error("Error"), 1);
		game->ceiling = get_colorcf(rgb[0], rgb[1], rgb[2]);
		return (0);
	}
	return (1);
}

int	ft_path(char **paths, t_hulk *game)
{
	int	i;

	i = 0;
	if (!game || check_duplicates(paths))
		return (1);
	game->map = my_malloc(sizeof(t_map));
	if (!game->map)
		return (1);
	while (paths && paths[i])
	{
		if (ft_strncmp(paths[i], "NO", 2) == 0)
			game->map->no = extract_path(paths[i]);
		else if (ft_strncmp(paths[i], "SO", 2) == 0)
			game->map->so = extract_path(paths[i]);
		else if (ft_strncmp(paths[i], "WE", 2) == 0)
			game->map->we = extract_path(paths[i]);
		else if (ft_strncmp(paths[i], "EA", 2) == 0)
			game->map->ea = extract_path(paths[i]);
		else if (get_color_paths(paths, i, game))
			return (1);
		i++;
	}
	if (!game->map->ea || !game->map->we || !game->map->so || !game->map->no)
		return (ft_error("Error"), 1);
	return (0);
}
