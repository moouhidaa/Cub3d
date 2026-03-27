/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:05:59 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"

static double	get_the_angle(char looking_to)
{
	if (looking_to == 'N')
		return (3 * PI / 2);
	if (looking_to == 'E')
		return (0);
	if (looking_to == 'S')
		return (PI / 2);
	else if (looking_to == 'W')
		return (PI);
	return (0x0000000);
}

static int	w_map(char **map)
{
	int	index;
	int	last_row;
	int	current;

	index = 0;
	last_row = 0;
	current = last_row;
	while (map && map[index])
	{
		current = ft_strlen(map[index]);
		if (current > last_row)
			last_row = current;
		index++;
	}
	return (last_row);
}

static int	count_rows(char **map)
{
	int	count;

	count = 0;
	while (map && map[count])
		count++;
	return (count);
}

int	init_player(t_hulk *game)
{
	game->keys = my_malloc(sizeof(t_keys));
	game->player = my_malloc(sizeof(t_player));
	if (!game->keys || !game->player)
		return (1);
	find_the_player_p(game->map->valid_map, game);
	game->player->p_x = (game->map->p_x * TILE) + TILE / 2;
	game->player->p_y = (game->map->p_y * TILE) + TILE / 2;
	game->player->anlge = get_the_angle(game->map->char_palyer);
	game->player->move_speed = MOVE_SPEED;
	game->player->rotate_speed = ROT_SPEED;
	game->keys->key_a = 0;
	game->keys->key_s = 0;
	game->keys->key_w = 0;
	game->keys->key_d = 0;
	game->keys->key_down = 0;
	game->keys->key_left = 0;
	game->keys->key_right = 0;
	game->keys->key_up = 0;
	game->keys->key_esc = 0;
	game->map->width = w_map(game->map->valid_map);
	game->map->height = count_rows(game->map->valid_map);
	return (0);
}
