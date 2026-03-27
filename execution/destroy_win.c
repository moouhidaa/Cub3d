/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:04:09 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"

int	destroy_windows(t_hulk *game)
{
	if (!game)
		return (0);
	if (game->connection && game->img)
		mlx_destroy_image(game->connection, game->img);
	if (game->connection && game->no.img)
		mlx_destroy_image(game->connection, game->no.img);
	if (game->connection && game->we.img)
		mlx_destroy_image(game->connection, game->we.img);
	if (game->connection && game->ea.img)
		mlx_destroy_image(game->connection, game->ea.img);
	if (game->connection && game->so.img)
		mlx_destroy_image(game->connection, game->so.img);
	if (game->connection && game->display)
		mlx_destroy_window(game->connection, game->display);
	if (game->connection)
	{
		mlx_destroy_display(game->connection);
		free(game->connection);
	}
	my_free();
	return (0);
}

void	set_the_ray(t_hulk *game, int i, double dist_hor, double dist_ver)
{
	if (dist_ver < dist_hor)
	{
		game->rays[i].distance = dist_ver;
		game->rays[i].hit_x = game->vertical_x_hit;
		game->rays[i].hit_y = game->vertical_y_hit;
		game->rays[i].side = 0;
	}
	else
	{
		game->rays[i].distance = dist_hor;
		game->rays[i].hit_x = game->horizontal_x_hit;
		game->rays[i].hit_y = game->horizontal_y_hit;
		game->rays[i].side = 1;
	}
	game->rays[i].correct_fish_eyes = game->rays[i].distance
		* cos(game->rays[i].angle - game->player->anlge);
}
