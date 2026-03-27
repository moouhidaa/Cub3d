/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:04:31 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

t_texture	*get_the_texture_side(t_ray *ray, t_hulk *game)
{
	if (ray->side == 0)
	{
		if (cos(ray->angle) > 0)
			return (&game->ea);
		return (&game->we);
	}
	else
	{
		if (sin(ray->angle) > 0)
			return (&game->so);
		return (&game->no);
	}
}

void	draw_pixel_wall(t_hulk *game, int screen_x, int texture_x)
{
	int	y;
	int	texture_y;
	int	color;
	int	slice_height;

	slice_height = game->wall_buttom - game->wall_top;
	y = 0;
	while (y < WIND_HIGHT)
	{
		if (y < game->wall_top)
			put_pixel(game, screen_x, y, game->ceiling);
		else if (y >= game->wall_top && y <= game->wall_buttom)
		{
			texture_y = (int)((y - game->wall_top)
					* ((float)game->wall_texture_ray->height / slice_height));
			color = get_pixel_color(game, texture_x, texture_y);
			put_pixel(game, screen_x, y, color);
		}
		else
			put_pixel(game, screen_x, y, game->floor);
		y++;
	}
}

void	draw_wall(t_hulk *game, int index_ray)
{
	int	offset_texture_x;

	game->wall_texture_ray = get_the_texture_side(&game->rays[index_ray], game);
	if (!game->wall_texture_ray)
	{
		perror("Error\n");
		return ;
	}
	if (game->rays[index_ray].side == 0)
		offset_texture_x = ((int)game->rays[index_ray].hit_y % TILE)
			* (game->wall_texture_ray->height / TILE);
	else
		offset_texture_x = ((int)game->rays[index_ray].hit_x % TILE)
			* (game->wall_texture_ray->height / TILE);
	draw_pixel_wall(game, index_ray, offset_texture_x);
}

void	rendering_texture(t_hulk *game)
{
	int		index_ray;
	int		wall_height;
	double	projection_distance;

	index_ray = 0;
	projection_distance = (WIN_WIDTH / 2) / tan(FOV / 2);
	while (index_ray < NUMBER_OF_RAYS)
	{
		wall_height = (TILE / game->rays[index_ray].correct_fish_eyes)
			* projection_distance;
		game->wall_top = (WIND_HIGHT / 2) - (wall_height / 2);
		game->wall_buttom = (WIND_HIGHT / 2) + (wall_height / 2);
		draw_wall(game, index_ray);
		index_ray++;
	}
}
