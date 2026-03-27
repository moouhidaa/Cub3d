/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/27 05:58:44 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/minilibx-linux/mlx.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_ARGS "Error\n The (name) Map > or < Number of Args Invalid"
# define ERROR_MAP_MSG "Error\nThe Map Invalid!"

# define PI 3.141592
# define WIN_WIDTH 1200
# define WIND_HIGHT 800
# define BAD_M 1
# define GOOD_M 0
# define FOV 0.66
# define ROT_SPEED 0.04
# define MOVE_SPEED 2
# define NUMBER_OF_RAYS WIN_WIDTH
# define TILE 64
# define MAX_DISTANCE __INT_MAX__

typedef struct t_player
{
	double		p_x;
	double		p_y;
	double		anlge;
	double		move_speed;
	double		rotate_speed;
}				t_player;

typedef struct t_keys
{
	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
	int			key_s;
	int			key_w;
	int			key_d;
	int			key_a;
	int			key_esc;
}				t_keys;

typedef struct s_rays
{
	double		hit_x;
	double		hit_y;
	double		distance;
	double		correct_fish_eyes;
	double		angle;
	int			side;
	double		wall_height;

}				t_ray;

typedef struct t_texture
{
	void		*img;
	char		*img_pixels;
	int			dpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	int			wall_leght;
}				t_texture;

typedef struct t_map
{
	char		**valid_map;
	char		char_palyer;
	int			width;
	int			height;
	int			p_x;
	int			p_y;
	char		*no;
	char		*ea;
	char		*we;
	char		*f;
	char		*c;
	char		*so;
}				t_map;

typedef struct t_counters
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
}				t_counters;

typedef struct t_hulk
{
	void		*connection;
	void		*display;
	void		*img;
	char		*img_pixel;
	int			bpp;
	int			size_line;
	int			endian;
	t_texture	so;
	t_texture	no;
	t_texture	ea;
	t_texture	we;
	t_texture	*wall_texture_ray;
	int			ceiling;
	int			floor;
	t_player	*player;
	t_map		*map;
	t_keys		*keys;
	t_ray		rays[NUMBER_OF_RAYS];
	double		horizontal_x_hit;
	double		vertical_x_hit;
	double		horizontal_y_hit;
	double		vertical_y_hit;
	double		wall_top;
	double		wall_buttom;
	int			fd;
}				t_hulk;

int				init_player(t_hulk *game);
void			launch_the_mlx(t_hulk *game);
int				frames(t_hulk *game);
void			cast_rays(t_hulk *game);
int				ray_going_down(double ray_angle);
int				ray_going_right(double ray_angle);
double			no_angle(double angle);
int				is_wall(t_hulk *game, double p_x, double p_y);
void			launch_the_mlx(t_hulk *game);
int				load_img_adresses(t_hulk *game);
void			rendering_texture(t_hulk *game);
double			get_the_distance(double px, double py, double interx,
					double intery);
void			set_the_ray(t_hulk *game, int index_ray, double hit_hor,
					double hit_ver);
void			put_pixel(t_hulk *game, int x, int y, int color);
int				get_pixel_color(t_hulk *game, int x, int y);
int				check_name(char *name);
int				parse_cub3d(char *filename, t_hulk *game);
int				read_textures_and_colors(char *file, t_hulk *game);
char			**my_realloc(char **tab, char *newline);
int				space_rounded(int top, int buttom, int left, int right);
int				check_duplicates(char **paths);
int				check_if_duplicate(char **paths, t_counters *count);
int				*extract_rgb(char *line);
int				is_position_safe(char **map, int row, int col);
int				get_safe_char(char **map, int row, int col);
int				check_closed_map(char **map);
int				is_valid_char(char c);
void			find_the_player_p(char **map, t_hulk *game);
char			*extract_path(char *line);
int				ft_validcolor(char *color_str);
int				ft_path(char **paths, t_hulk *game);
int				has_xpm_extension(char *path);
int				ft_check_player(char **map);
void			*my_malloc(size_t size);
void			my_free(void);
int				mini_atoi(char *n, int *i);
void			ft_error(char *msg);
int				destroy_windows(t_hulk *game);
void			intersection_steps(double *x_step, double *y_step, double angle,
					int type);
void			init_xy_v(double angle, double *x, double *y, t_hulk *game);
void			init_xy_h(double angle, double *x, double *y, t_hulk *game);
int				nl(int fd, char *line);
int				onlyw(char *s);
#endif
