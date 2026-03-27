/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:29:17 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 09:29:18 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_the_player_p(char **map, t_hulk *game)
{
	int	index_x;
	int	index_y;

	index_x = 0;
	index_y = 0;
	while (map && map[index_x])
	{
		index_y = 0;
		while (map && map[index_x][index_y])
		{
			if (ft_isalpha(map[index_x][index_y]))
			{
				game->map->p_x = index_y;
				game->map->p_y = index_x;
				game->map->char_palyer = map[index_x][index_y];
				return ;
			}
			index_y++;
		}
		index_x++;
	}
}
