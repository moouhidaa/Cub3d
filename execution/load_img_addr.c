/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:03:10 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"

static void	cleanup_textures(t_hulk *game)
{
	if (!game || !game->connection)
		return ;
	if (game->no.img)
	{
		mlx_destroy_image(game->connection, game->no.img);
		game->no.img = NULL;
	}
	if (game->ea.img)
	{
		mlx_destroy_image(game->connection, game->ea.img);
		game->ea.img = NULL;
	}
	if (game->so.img)
	{
		mlx_destroy_image(game->connection, game->so.img);
		game->so.img = NULL;
	}
	if (game->we.img)
	{
		mlx_destroy_image(game->connection, game->we.img);
		game->we.img = NULL;
	}
}

int	secondload(t_hulk *game)
{
	game->we.img = mlx_xpm_file_to_image(game->connection, game->map->we,
			&game->we.width, &game->we.height);
	if (!game->we.img)
		return (cleanup_textures(game), ft_error("Error"), 1);
	game->we.img_pixels = mlx_get_data_addr(game->we.img, &game->we.dpp,
			&game->we.size_line, &game->we.endian);
	game->so.img = mlx_xpm_file_to_image(game->connection, game->map->so,
			&game->so.width, &game->so.height);
	if (!game->so.img)
		return (cleanup_textures(game), ft_error("Error"), 1);
	game->so.img_pixels = mlx_get_data_addr(game->so.img, &game->so.dpp,
			&game->so.size_line, &game->so.endian);
	return (0);
}

int	load_img_adresses(t_hulk *game)
{
	if (!game || !game->connection)
		return (ft_error("Error"), 1);
	if (game->no.img && game->ea.img && game->so.img && game->we.img)
		return (0);
	game->no.img = mlx_xpm_file_to_image(game->connection, game->map->no,
			&game->no.width, &game->no.height);
	if (!game->no.img)
		return (cleanup_textures(game), ft_error("Error"), 1);
	game->no.img_pixels = mlx_get_data_addr(game->no.img, &game->no.dpp,
			&game->no.size_line, &game->no.endian);
	game->ea.img = mlx_xpm_file_to_image(game->connection, game->map->ea,
			&game->ea.width, &game->ea.height);
	if (!game->ea.img)
		return (cleanup_textures(game), ft_error("Error"), 1);
	game->ea.img_pixels = mlx_get_data_addr(game->ea.img, &game->ea.dpp,
			&game->ea.size_line, &game->ea.endian);
	if (secondload(game))
		return (1);
	return (0);
}
