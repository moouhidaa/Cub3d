#include "../../cub3d.h"

void	raycast_column(t_game *game, int x, t_ray *ray)
{
	double	abs_ddx;
	double	abs_ddy;

	ray->camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	abs_ddx = fabs(ray->ray_dir_x);
	abs_ddy = fabs(ray->ray_dir_y);
	ray->delta_dist_x = (abs_ddx < 1e-20) ? 1e30 : fabs(1.0 / ray->ray_dir_x);
	ray->delta_dist_y = (abs_ddy < 1e-20) ? 1e30 : fabs(1.0 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
	}
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y >= 0 && ray->map_y < game->map.rows
			&& ray->map_x >= 0 && ray->map_x < game->map.cols
			&& game->map.grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			ray->tex_num = EAST;
		else
			ray->tex_num = WEST;
	}
	else
	{
		if (ray->step_y > 0)
			ray->tex_num = SOUTH;
		else
			ray->tex_num = NORTH;
	}
	if (ray->side == 0)
		ray->wall_x = game->player.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x
		* (double)game->textures[ray->tex_num].width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = game->textures[ray->tex_num].width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = game->textures[ray->tex_num].width - ray->tex_x - 1;
}

void	draw_column(t_game *game, int x, t_ray *ray)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	int		y;
	t_img	*tex;

	tex = &game->textures[ray->tex_num];
	step = (double)tex->height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		color = get_pixel(tex, ray->tex_x, tex_y);
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		pixel_put(&game->screen, x, y, color);
		y++;
	}
}

void	render_frame(t_game *game)
{
	t_ray	ray;
	int		x;

	draw_ceiling_floor(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		raycast_column(game, x, &ray);
		draw_column(game, x, &ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->screen.img, 0, 0);
}
