/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:17 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 08:58:29 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"
#include "../parser.h"

static bool	parse_asset_line(t_cub *cub)
{
	char	**chunks;

	chunks = ft_split(cub->parser.map_file_lines[cub->parser.load_map.index],
			' ');
	if (!chunks)
		return (FAILED);
	chunks = normalize_tokens(chunks);
	if (!chunks[0] || !chunks[1])
		return (FAILED);
	if (!assign_textures_and_colors(cub, chunks))
		return (FAILED);
	cub->parser.load_map.index++;
	return (SUCCESS);
}

static bool	parse_textures_and_colors(t_cub *cub)
{
	while (cub->parser.map_file_lines[cub->parser.load_map.index])
	{
		skip_empty_lines(cub);
		if (!cub->parser.map_file_lines[cub->parser.load_map.index])
			break ;
		if (parse_asset_line(cub) == FAILED)
			break ;
	}
	return (validate_assets(cub));
}

static bool	open_and_allocate(t_cub *cub)
{
	t_load_map	*load_map;

	load_map = &cub->parser.load_map;
	load_map->size = map_line_count(cub);
	if (load_map->size == ERROR)
		return (FAILED);
	load_map->fd = open(cub->parser.map_file_path, O_RDONLY);
	if (load_map->fd == ERROR)
	{
		ft_putstr_fd("Error: Unable to open map file\n", 2);
		return (FAILED);
	}
	cub->parser.map_file_lines = ft_malloc(sizeof(char *) * (load_map->size
				+ 1));
	return (SUCCESS);
}

static bool	load_map_file(t_cub *cub)
{
	if (open_and_allocate(cub) == FAILED)
		return (FAILED);
	if (read_file_lines(cub) == FAILED)
		return (close(cub->parser.load_map.fd), FAILED);
	close(cub->parser.load_map.fd);
	return (parse_textures_and_colors(cub));
}

bool	parser(t_cub *cub, char *map_file_path)
{
	if (!check_file_extension(map_file_path, ".cub"))
	{
		ft_putstr_fd("Error: Invalid file extension. Expected .cub\n", 2);
		return (FAILED);
	}
	cub->parser.map_file_path = map_file_path;
	if (load_map_file(cub))
	{
		ft_putstr_fd("Error: Failed to load map file\n", 2);
		return (FAILED);
	}
	if (load_and_validate_map(cub))
	{
		ft_putstr_fd("Error: Failed to parse map grid\n", 2);
		return (FAILED);
	}
	cub->floor_color = create_rgb(cub->parser.floor_color.r,
			cub->parser.floor_color.g,
			cub->parser.floor_color.b);
	cub->ceiling_color = create_rgb(cub->parser.ceiling_color.r,
			cub->parser.ceiling_color.g, cub->parser.ceiling_color.b);
	return (SUCCESS);
}
