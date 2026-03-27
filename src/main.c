#include "../cub3d.h"

static int	load_texture(t_game *game, int idx)
{
	t_img	*tex;

	tex = &game->textures[idx];
	tex->img = mlx_xpm_file_to_image(game->mlx,
		game->map.tex_path[idx], &tex->width, &tex->height);
	if (!tex->img)
		return (1);
	tex->addr = mlx_get_data_addr(tex->img,
		&tex->bpp, &tex->line_len, &tex->endian);
	if (!tex->addr)
		return (1);
	return (0);
}

static void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_texture(game, i) != 0)
			error_exit(ERR_TEX, game);
		i++;
	}
}

static void	init_screen(t_game *game)
{
	game->screen.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->screen.img)
		error_exit(ERR_MLX, game);
	game->screen.addr = mlx_get_data_addr(game->screen.img,
		&game->screen.bpp, &game->screen.line_len, &game->screen.endian);
	game->screen.width = WIN_WIDTH;
	game->screen.height = WIN_HEIGHT;
}

static void	init_game(t_game *game, const char *filename)
{
	memset(game, 0, sizeof(t_game));
	game->map.floor_color = -1;
	game->map.ceil_color = -1;
	parse_file(game, filename);
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(ERR_MLX, game);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		error_exit(ERR_MLX, game);
	init_screen(game);
	load_textures(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit(ERR_ARGS, NULL);
	init_game(&game, argv[1]);
	mlx_hook(game.win, ON_KEYDOWN, 1L << 0, handle_keydown, &game);
	mlx_hook(game.win, ON_KEYUP, 1L << 1, handle_keyup, &game);
	mlx_hook(game.win, ON_DESTROY, 0, handle_destroy, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
