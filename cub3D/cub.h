/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:31:05 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/26 12:55:28 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "libft/libft.h"
# include "mlx/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MLX_KEY_ESC 256
# define MLX_KEY_RIGHT 262
# define MLX_KEY_LEFT 263

# define MLX_KEY_W 87
# define MLX_KEY_S 83
# define MLX_KEY_A 65
# define MLX_KEY_D 68
# define MLX_KEY_SPACE 49
# define WIDTH 1800
# define HEIGHT 1200
# define TILE_SIZE 32
# define FOV_ANGLE 1.047198
# define NUM_RAYS WIDTH
# define SCALE 0.5
// #define malloc(x) NULL
typedef struct s_mini_map
{
	int				map_width;
	int				map_height;
	double			x_start;
	double			y_start;
	double			x_end;
	double			y_end;
	double			x;
	double			y;
	double			x1;
	double			y1;

}					t_mini_map;

typedef struct s_direction
{
	int				is_up;
	int				is_down;
	int				is_right;
	int				is_left;
}					t_direction;

typedef struct s_vars
{
	double			xintercept;
	double			yintercept;
	double			xinc;
	double			yinc;
	double			xhit;
	double			yhit;
	double			next_x;
	double			next_y;

}					t_vars;
typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_ray
{
	char			hit;
	char			v_hitting_on;
	char			h_hitting_on;
	char			hitting_on;
	float			angle;
	float			x_horz;
	float			y_horz;
	float			x_vert;
	float			y_vert;
	float			x_horz_sp;
	float			y_horz_sp;
	float			x_vert_sp;
	float			y_vert_sp;
	float			y;
	float			x;
	float			distance;
	bool			animated_sp;
	float			sp_distance;
	char			sp_hit;
}					t_ray;

typedef struct s_start
{
	double			x;
	double			y;
	char			dir;
	double			rotation_angle;
	double			radius;
	double			move_speed;
	double			rotation_speed;
	double			walk_direction;
	double			turn_direction;

}					t_start;

typedef struct s_door
{
	int				x;
	int				y;
	int				opening_persentage;
	bool			is_open;
	char			direction;
	struct s_door	*next;
}					t_door;

typedef struct s_cub
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*doo;
	mlx_texture_t	*no_txt;
	mlx_texture_t	*so_txt;
	mlx_texture_t	*we_txt;
	mlx_texture_t	*ea_txt;
	mlx_texture_t	*do_txt;
	int				f[3];
	int				c[3];
	char			**map;
	t_start			s;
	int				door_count;
	t_door			*door;
}					t_cub;

typedef struct s_mlx
{
	mlx_t			*win;
	mlx_texture_t	*sp_tex1;
	mlx_texture_t	*sp_tex2;
	mlx_texture_t	*sp_tex3;
	mlx_image_t		*img;
	int				map_width;
	int				map_height;
	t_cub			*cub;
	t_ray			*ray;
	double			fov;
	double			angle;
	struct timeval	time;
}					t_mlx;

typedef struct s_wall
{
	int				fd;
	int				i;
	char			*line;
	char			**buffer;
	char			*tmp;
}					t_wall;

void				ft_color(int *color, char *s);
void				ft_wall(t_cub *cube, char *file);
t_direction			set_direction(double angle);
void				ft_error(char *s);
void				ft_check_access(char *s);

void				ft_check(int c, char *s);
void				ft_render(t_mlx *mlx);
void				ft_put_in(int x, int y, mlx_image_t *img, int color);
void				ft_draw3d(t_mlx *mlx, double angle, int i, int x);
int					get_texture_color(t_mlx *mlx, int x, int tex_y, int *data);
void				ft_distance(t_mlx *mlx);
void				mini_map(t_mlx *mlx);

void				key_press(mlx_key_data_t key_data, void *param);
void				get_vertical(t_mlx *mlx, double angle, int i);
void				get_horizontal(t_mlx *mlx, double angle, int i);
double				normalize_angle(double angle);
double				get_min(double a, double b);
int					has_wall_at(t_mlx *mlx, double x, double y);
void				check_surrounding(t_cub *cub, int x, int y);
int					check_diagonal(t_cub *cub, t_door *door, int x, int y);
int					check_orthogonal(t_cub *cub, t_door *door, int x, int y);
int					check_if_open(t_cub *cub, double x, double y);

void				color_inint(int *color);
void				free_texture(char **lines, char *message);
int					get_pixel_color(mlx_texture_t *texture, int tex_x,
						int tex_y, int *data);
void				ft_map(t_cub *cube, char *file);
int					ft_arrsize(char **arr);
void				print_map(char **map);
int					check_texture(char *line);
char				**extract_map(char **parts);
void				handle_door(t_cub *cube, int i, int j);
void				check_player_and_fill(t_cub *cube, int player_count);
void				double_fill(t_cub *cube, double x, double y);
void				draw_sprite(t_mlx *mlx, mlx_texture_t *tex);
mlx_texture_t		*chose_sp_tex(t_mlx *mlx);
void				calculate_distance(t_mlx *mlx, int i);
int					check_tile(t_mlx *mlx);
void				key_escape(int key_code, t_mlx *mlx);
void				key_left(mlx_key_data_t key_data, t_mlx *mlx);
void				key_right(mlx_key_data_t key_data, t_mlx *mlx);
void				spread(t_cub *cube, double x, double y);
void				draw_game_border(t_mlx *mlx);

#endif
