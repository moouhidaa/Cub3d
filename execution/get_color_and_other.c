/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_and_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:03:21 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"

void	put_pixel(t_hulk *game, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIND_HIGHT)
		return ;
	offset = (y * game->size_line) + (x * (game->bpp / 8));
	*(unsigned int *)(game->img_pixel + offset) = color;
}

int	get_pixel_color(t_hulk *game, int x, int y)
{
	char	*px;

	if (x < 0 || x >= game->wall_texture_ray->width || y < 0
		|| y >= game->wall_texture_ray->height)
		return (0x000000);
	if (game->wall_texture_ray->dpp <= 0
		|| game->wall_texture_ray->size_line <= 0)
		return (0x000000);
	px = game->wall_texture_ray->img_pixels + (y
			* game->wall_texture_ray->size_line) + (x
			* (game->wall_texture_ray->dpp / 8));
	return (*(unsigned int *)px);
}

int	is_wall(t_hulk *game, double p_x, double p_y)
{
	int	x;
	int	y;

	if (!game || !game->map)
		return (1);
	if (p_x < 0 || p_y < 0 || p_x >= game->map->width * TILE
		|| p_y >= game->map->height * TILE)
		return (1);
	x = (int)(p_x / TILE);
	y = (int)(p_y / TILE);
	if (x < 0 || y < 0 || x >= game->map->width || y >= game->map->height)
		return (1);
	if (!game->map->valid_map[y]
		|| (int)ft_strlen(game->map->valid_map[y]) <= x)
		return (1);
	return (game->map->valid_map[y][x] == '1');
}
