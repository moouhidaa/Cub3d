/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:30:04 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 09:30:05 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c <= 32 || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

static int	is_empty(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_closed_map(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (is_empty(map[row][col]))
			{
				if (is_position_safe(map, row, col))
				{
					ft_error("Error");
					return (1);
				}
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_check_player(char **map)
{
	int		i;
	int		count;
	int		j;
	char	c;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 0 || count > 1)
		return (1);
	return (0);
}
