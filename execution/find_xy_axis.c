/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_xy_axis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:03:59 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	init_xy_v(double angle, double *x, double *y, t_hulk *game)
{
	*x = floor(game->player->p_x / TILE) * TILE;
	if (cos(angle) > 0)
		*x += TILE;
	*y = game->player->p_y + (*x - game->player->p_x) * tan(angle);
}

void	init_xy_h(double angle, double *x, double *y, t_hulk *game)
{
	*y = floor(game->player->p_y / TILE) * TILE;
	if (ray_going_down(angle))
		*y += TILE;
	*x = game->player->p_x + (*y - game->player->p_y) / tan(angle);
}
