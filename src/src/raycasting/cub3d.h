/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:57:37 by bchiki            #+#    #+#             */
/*   Updated: 2026/03/05 17:49:52 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../mlx/mlx.h"
# include "../parsing/parser.h"
# include "../utils/utils.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TEXTURE_SIZE 64
# define FOV 60
# define MOVE_SPEED 0.03
# define ROTATION_SPEED 0.02

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_window
{
	void		*window_init;
	void		*window_display;
	int			window_width;
	int			window_height;
}				t_window;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		orientation;
}				t_player;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	double		wall_x;
}				t_ray;

typedef struct s_slide_data
{
	double		new_x;
	double		new_y;
	int			gx;
	int			gy;
}				t_slide_data;

typedef struct s_draw_ctx
{
	char		*base;
	int			stride;
	int			height;
}				t_draw_ctx;

typedef struct s_cub
{
	t_window	window;
	t_image		image;
	t_parser	parser;
	t_player	player;
	t_texture	textures[4];
	int			floor_color;
	int			ceiling_color;
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_left;
	int			key_right;
}				t_cub;

bool			init_window(t_cub *cub);
void			init_player(t_cub *cub);
bool			load_textures(t_cub *cub);
void			ray_casting(t_cub *cub);
void			draw_pixel(t_image *image, int x, int y, int color);
int				get_pixel_color(t_texture *texture, int x, int y);
int				create_rgb(unsigned char r, unsigned char g, unsigned char b);
int				key_press(int keycode, t_cub *cub);
int				key_release(int keycode, t_cub *cub);
int				game_loop(t_cub *cub);
int				close_window(t_cub *cub);
void			move_player(t_cub *cub, int direction);
void			strafe_player(t_cub *cub, int direction);
void			rotate_player(t_cub *cub, int direction);
void			free_resources(t_cub *cub);
void			init_ray(t_cub *cub, t_ray *ray, int x);
void			calculate_step_and_side_dist(t_ray *ray, t_player *player);
void			perform_dda(t_cub *cub, t_ray *ray);
void			calculate_wall_distance(t_ray *ray, t_player *player,
					int height);
int				determine_texture(t_ray *ray);
void			calculate_texture_x(t_ray *ray, t_player *player);
void			draw_vertical_line(t_cub *cub, t_ray *ray, int x,
					int texture_num);
void			draw_ceiling(t_cub *cub, t_draw_ctx *ctx, int end);
void			draw_textured_wall(t_cub *cub, t_ray *ray, t_draw_ctx *ctx,
					int tex_num);
void			draw_floor(t_cub *cub, t_draw_ctx *ctx, int start);
int				check_basic_collision(t_cub *cub, int gx, int gy);
void			try_x_slide(t_cub *cub, double cand_x, int gy_cur, int gx);
void			try_y_slide(t_cub *cub, double cand_y, int gy, int gx_cur);
void			handle_player_input(t_cub *cub);

#endif
