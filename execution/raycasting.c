/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:21 by moouhida          #+#    #+#             */
/*   Updated: 2026/01/04 11:01:49 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	found_the_vertical(t_hulk *game, double angle)
{
	double	x;
	double	y;
	double	x_step;
	double	y_step;
	int		side;

	intersection_steps(&x_step, &y_step, angle, 1);
	init_xy_v(angle, &x, &y, game);
	while (x >= 0 && y >= 0 && x < game->map->width * TILE
		&& y < game->map->height * TILE)
	{
		side = 0;
		if (!ray_going_right(angle))
			side = -1;
		if (is_wall(game, x + side, y))
			return (game->vertical_y_hit = y, game->vertical_x_hit = x, 1);
		x += x_step;
		y += y_step;
	}
	return (0);
}

int	found_the_horizontal(t_hulk *game, double angle)
{
	double	x;
	double	y;
	double	x_step;
	double	y_step;
	int		side;

	intersection_steps(&x_step, &y_step, angle, 0);
	init_xy_h(angle, &x, &y, game);
	while (x >= 0 && y >= 0 && x < game->map->width * TILE
		&& y < game->map->height * TILE)
	{
		side = 0;
		if (!ray_going_down(angle))
			side = -1;
		if (is_wall(game, x, y + side))
		{
			game->horizontal_x_hit = x;
			game->horizontal_y_hit = y;
			return (1);
		}
		x += x_step;
		y += y_step;
	}
	return (0);
}

void	cast_it(t_hulk *game, size_t index_ray)
{
	double	dist_h;
	double	dist_v;

	dist_h = MAX_DISTANCE;
	dist_v = MAX_DISTANCE;
	game->rays[index_ray].angle = no_angle(game->rays[index_ray].angle);
	if (found_the_vertical(game, game->rays[index_ray].angle))
		dist_v = get_the_distance(game->player->p_x, game->player->p_y,
				game->vertical_x_hit, game->vertical_y_hit);
	if (found_the_horizontal(game, game->rays[index_ray].angle))
		dist_h = get_the_distance(game->player->p_x, game->player->p_y,
				game->horizontal_x_hit, game->horizontal_y_hit);
	set_the_ray(game, index_ray, dist_h, dist_v);
}

void	cast_rays(t_hulk *game)
{
	double	angle;
	size_t	i;

	angle = game->player->anlge - (FOV / 2);
	i = 0;
	while (i < NUMBER_OF_RAYS)
	{
		game->rays[i].angle = angle;
		cast_it(game, i);
		angle += FOV / NUMBER_OF_RAYS;
		i++;
	}
}
