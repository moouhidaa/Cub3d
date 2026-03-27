#include "../cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < 4)
	{
		if (map->tex_path[i])
			free(map->tex_path[i]);
		map->tex_path[i] = NULL;
		i++;
	}
	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	free_map(&game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	error_exit(const char *msg, t_game *game)
{
	fprintf(stderr, "%s\n", msg);
	if (game)
		free_game(game);
	exit(1);
}
