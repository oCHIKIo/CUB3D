/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:22:04 by mhaddou           #+#    #+#             */
/*   Updated: 2026/03/05 17:49:56 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../mlx/mlx.h"
# include <stdbool.h>

typedef struct s_cub	t_cub;

typedef struct s_fnd_plyr
{
	int					i;
	int					j;
	int					player_count;
}						t_fnd_plyr;

typedef struct s_jwithspace
{
	int					len1;
	int					len2;
	char				*result;
	int					i;
	int					j;
}						t_jwithspace;

typedef struct s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	bool				valid;
}						t_color;

typedef struct s_load_map
{
	int					fd;
	char				*line;
	int					index;
	int					size;
}						t_load_map;

typedef struct s_parser
{
	char				*map_file_path;
	char				**map_file_lines;
	t_load_map			load_map;
	char				**map_grid;
	int					map_height;
	int					*map_width;
	t_color				floor_color;
	t_color				ceiling_color;
	char				*north_texture_path;
	char				*south_texture_path;
	char				*west_texture_path;
	char				*east_texture_path;
}						t_parser;

bool					validate_map(t_cub *cub);
bool					is_valid_map_char(char c);
char					*trim_copy(const char *s);
bool					is_empty_string(char *str);
bool					is_player_position(char c);
int						map_line_count(t_cub *cub);
bool					read_file_lines(t_cub *cub);
bool					validate_assets(t_cub *cub);
bool					assign_map_grid(t_cub *cub);
void					skip_empty_lines(t_cub *cub);
char					**normalize_tokens(char **chunks);
bool					load_and_validate_map(t_cub *cub);
bool					is_valid_rgb_value(char *rgb_str);
char					*join_with_space(char *s1, char *s2);
bool					validate_row_chars(t_cub *cub, int i);
bool					parser(t_cub *cub, char *map_file_path);
int						assign_colors(t_cub *cub, char **chunks);
int						assign_texture(t_cub *cub, char **chunks);
void					set_player_position(t_cub *cub, int i, int j);
bool					assign_west_texture(t_cub *cub, char **chunks);
bool					assign_east_texture(t_cub *cub, char **chunks);
bool					assign_north_texture(t_cub *cub, char **chunks);
bool					assign_south_texture(t_cub *cub, char **chunks);
bool					check_file_extension(char *file_path, char *ext);
bool					assign_textures_and_colors(t_cub *cub, char **chunks);
char					get_char_at(t_cub *cub, int y, int x);
bool					check_cell_neighbors(t_cub *cub, int i, int j);
bool					check_walls_closed(t_cub *cub);
bool					flood_fill_check(t_cub *cub, int y, int x, char **v);
void					init_visited(char **visited, int *map_width, int h);
char					**alloc_visited(t_cub *cub);
bool					run_flood_fill(t_cub *cub, char **visited);
bool					validate_map_closed(t_cub *cub);
bool					validate_map_characters(t_cub *cub);
bool					process_player_row(t_cub *cub, t_fnd_plyr *x);
bool					find_player(t_cub *cub);

#endif
