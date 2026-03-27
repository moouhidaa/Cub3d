/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_the_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:40 by moouhida          #+#    #+#             */
/*   Updated: 2026/01/04 09:39:03 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	set_value_to_1(int key, t_hulk *game)
{
	if (key == XK_Escape)
		game->keys->key_esc = 1;
	if (key == XK_a)
		game->keys->key_a = 1;
	if (key == XK_s)
		game->keys->key_s = 1;
	if (key == XK_w)
		game->keys->key_w = 1;
	if (key == XK_d)
		game->keys->key_d = 1;
	if (key == XK_Up)
		game->keys->key_up = 1;
	if (key == XK_Down)
		game->keys->key_down = 1;
	if (key == XK_Left)
		game->keys->key_left = 1;
	if (key == XK_Right)
		game->keys->key_right = 1;
	return (0);
}

int	set_value_to_0(int key, t_hulk *game)
{
	if (key == XK_a)
		game->keys->key_a = 0;
	if (key == XK_s)
		game->keys->key_s = 0;
	if (key == XK_w)
		game->keys->key_w = 0;
	if (key == XK_d)
		game->keys->key_d = 0;
	if (key == XK_Up)
		game->keys->key_up = 0;
	if (key == XK_Down)
		game->keys->key_down = 0;
	if (key == XK_Left)
		game->keys->key_left = 0;
	if (key == XK_Right)
		game->keys->key_right = 0;
	return (0);
}

void	launch_the_mlx(t_hulk *game)
{
	game->connection = mlx_init();
	game->display = mlx_new_window(game->connection, WIN_WIDTH, WIND_HIGHT,
			"CUB3D");
	if (!game->connection || !game->display)
	{
		my_free();
		return ;
	}
	mlx_hook(game->display, KeyPress, KeyPressMask, set_value_to_1, game);
	mlx_hook(game->display, KeyRelease, KeyReleaseMask, set_value_to_0, game);
	mlx_loop_hook(game->connection, frames, game);
	mlx_hook(game->display, 17, 0, destroy_windows, game);
	mlx_loop(game->connection);
}
