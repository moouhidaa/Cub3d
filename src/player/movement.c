#include "../../cub3d.h"

static void	move_forward_back(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * speed;
	new_y = game->player.pos_y + game->player.dir_y * speed;
	if (new_x >= 0 && new_x < game->map.cols
		&& game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (new_y >= 0 && new_y < game->map.rows
		&& game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

static void	move_strafe(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.plane_x * speed;
	new_y = game->player.pos_y + game->player.plane_y * speed;
	if (new_x >= 0 && new_x < game->map.cols
		&& game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (new_y >= 0 && new_y < game->map.rows
		&& game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

static void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}

int	game_loop(t_game *game)
{
	if (game->keys[KEY_W])
		move_forward_back(game, MOVE_SPEED);
	if (game->keys[KEY_S])
		move_forward_back(game, -MOVE_SPEED);
	if (game->keys[KEY_A])
		move_strafe(game, -MOVE_SPEED);
	if (game->keys[KEY_D])
		move_strafe(game, MOVE_SPEED);
	if (game->keys[KEY_LEFT])
		rotate_player(game, -ROT_SPEED);
	if (game->keys[KEY_RIGHT])
		rotate_player(game, ROT_SPEED);
	render_frame(game);
	return (0);
}
