#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "mlx_linux/mlx.h"

/* Window dimensions */
# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

/* Player movement and rotation speeds */
# define MOVE_SPEED 0.05
# define ROT_SPEED  0.03

/* Texture indices */
# define NORTH 0
# define SOUTH 1
# define WEST  2
# define EAST  3

/* Linux key codes */
# define KEY_W     119
# define KEY_A     97
# define KEY_S     115
# define KEY_D     100
# define KEY_LEFT  65361
# define KEY_RIGHT 65363
# define KEY_ESC   65307

/* MLX event codes */
# define ON_KEYDOWN 2
# define ON_KEYUP   3
# define ON_DESTROY 17

/* Error messages */
# define ERR_ARGS   "Error\nUsage: ./cub3d <map.cub>"
# define ERR_EXT    "Error\nMap file must have .cub extension"
# define ERR_OPEN   "Error\nFailed to open file"
# define ERR_MAP    "Error\nInvalid map configuration"
# define ERR_TEX    "Error\nInvalid or missing texture"
# define ERR_COLOR  "Error\nInvalid color value"
# define ERR_PLAYER "Error\nInvalid player position"
# define ERR_MLX    "Error\nMLX initialization failed"
# define ERR_MEM    "Error\nMemory allocation failed"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
}	t_ray;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	*tex_path[4];
	int		floor_color;
	int		ceil_color;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_img		textures[4];
	t_player	player;
	t_map		map;
	int			keys[65536];
}	t_game;

/* Parsing */
int		parse_file(t_game *game, const char *filename);
int		parse_config_line(t_game *game, char *line, int *map_found);
int		parse_map_lines(t_game *game, char **lines, int start, int total);
int		validate_map(t_game *game);
int		set_player_start(t_game *game, int row, int col, char dir);

/* Rendering */
void	render_frame(t_game *game);
void	raycast_column(t_game *game, int x, t_ray *ray);
void	draw_column(t_game *game, int x, t_ray *ray);
void	draw_ceiling_floor(t_game *game);

/* Player / Input */
int		handle_keydown(int keycode, t_game *game);
int		handle_keyup(int keycode, t_game *game);
int		game_loop(t_game *game);
int		handle_destroy(t_game *game);

/* Utilities */
void	pixel_put(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
int		create_color(int r, int g, int b);
void	free_game(t_game *game);
int		error_exit(const char *msg, t_game *game);

/* String utilities */
char	*ft_strdup(const char *s);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
int		ft_strlen(const char *s);
int		ft_atoi(const char *s);
void	ft_free_split(char **arr);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_isspace(char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, int n);

#endif
