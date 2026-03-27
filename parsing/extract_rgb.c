/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:29:09 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 10:47:48 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	*extract_rgb(char *line)
{
	int	*rgb;
	int	i;
	int	count;

	(1) && (i = 0, count = 0);
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	while (line[i] == ' ')
		i++;
	if (!ft_validcolor(line + i))
		return (NULL);
	rgb = my_malloc(sizeof(int) * 3);
	if (!rgb)
		return (NULL);
	while (count < 3)
	{
		while (line[i] == ' ')
			i++;
		rgb[count++] = mini_atoi(line, &i);
		while (line[i] == ' ')
			i++;
		if (line[i] == ',')
			i++;
	}
	return (rgb);
}

int	get_safe_char(char **map, int row, int col)
{
	if (!map[row])
		return (' ');
	if (col >= ft_strlen(map[row]))
		return (' ');
	return (map[row][col]);
}

int	is_position_safe(char **map, int row, int col)
{
	char	top;
	char	bottom;
	char	left;
	char	right;

	if (row == 0 || col == 0)
		return (1);
	if (!map[row + 1] || col >= ft_strlen(map[row]) - 1)
		return (1);
	top = get_safe_char(map, row - 1, col);
	bottom = get_safe_char(map, row + 1, col);
	left = map[row][col - 1];
	right = map[row][col + 1];
	if (map[row][col] <= 32)
	{
		if (space_rounded(top, bottom, left, right))
			return (1);
		return (0);
	}
	if (top == ' ' || bottom == ' ' || left == ' ' || right == ' ')
		return (1);
	return (0);
}
