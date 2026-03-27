#include "../../cub3d.h"

int	handle_keydown(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		handle_destroy(game);
	if (keycode >= 0 && keycode < 65536)
		game->keys[keycode] = 1;
	return (0);
}

int	handle_keyup(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < 65536)
		game->keys[keycode] = 0;
	return (0);
}

int	handle_destroy(t_game *game)
{
	free_game(game);
	exit(0);
}
