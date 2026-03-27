/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:04:50 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"

void	check_the_asdw(t_hulk *game, double *p_x, double *p_y)
{
	if (game->keys->key_d)
	{
		*p_x -= sin(game->player->anlge) * MOVE_SPEED;
		*p_y += cos(game->player->anlge) * MOVE_SPEED;
	}
	if (game->keys->key_w || game->keys->key_up)
	{
		*p_x += cos(game->player->anlge) * MOVE_SPEED;
		*p_y += sin(game->player->anlge) * MOVE_SPEED;
	}
	if (game->keys->key_s || game->keys->key_down)
	{
		*p_x -= cos(game->player->anlge) * MOVE_SPEED;
		*p_y -= sin(game->player->anlge) * MOVE_SPEED;
	}
	if (game->keys->key_a)
	{
		*p_x += sin(game->player->anlge) * MOVE_SPEED;
		*p_y -= cos(game->player->anlge) * MOVE_SPEED;
	}
}

int	collition_detection(t_hulk *game, double p_x, double p_y)
{
	double	step;

	step = 0.1;
	if (is_wall(game, p_x - step, p_y - step))
		return (1);
	if (is_wall(game, p_x + step, p_y + step))
		return (1);
	if (is_wall(game, p_x + step, p_y - step))
		return (1);
	if (is_wall(game, p_x - step, p_y + step))
		return (1);
	if (is_wall(game, p_x, p_y))
		return (1);
	return (0);
}

void	set_new_player_position(t_hulk *game)
{
	double	p_x;
	double	p_y;

	p_x = game->player->p_x;
	p_y = game->player->p_y;
	if (game->keys->key_esc)
		destroy_windows(game);
	if (game->keys->key_right)
		game->player->anlge += ROT_SPEED;
	if (game->keys->key_left)
		game->player->anlge -= ROT_SPEED;
	game->player->anlge = no_angle(game->player->anlge);
	check_the_asdw(game, &p_x, &p_y);
	if (!collition_detection(game, p_x, p_y))
	{
		game->player->p_x = p_x;
		game->player->p_y = p_y;
	}
}

int	frames(t_hulk *game)
{
	game->img = mlx_new_image(game->connection, WIN_WIDTH, WIND_HIGHT);
	game->img_pixel = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	if (!game->img || !game->img_pixel || load_img_adresses(game))
		return (destroy_windows(game), 1);
	set_new_player_position(game);
	cast_rays(game);
	rendering_texture(game);
	mlx_put_image_to_window(game->connection, game->display, game->img, 0, 0);
	mlx_destroy_image(game->connection, game->img);
	game->img = NULL;
	return (0);
}
