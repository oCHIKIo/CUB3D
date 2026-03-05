/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:26 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:21:26 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"
#include "../parser.h"

static bool	is_valid_texture_path(char *path)
{
	int	fd;

	if (!path)
		return (false);
	if (!check_file_extension(path, ".xpm"))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

int	assign_texture(t_cub *cub, char **chunks)
{
	if (assign_north_texture(cub, chunks) == SUCCESS
		|| assign_south_texture(cub, chunks) == SUCCESS
		|| assign_west_texture(cub, chunks) == SUCCESS
		|| assign_east_texture(cub, chunks) == SUCCESS)
		return (SUCCESS);
	return (FAILED);
}

static bool	validate_textures(t_cub *cub)
{
	if (!is_valid_texture_path(cub->parser.north_texture_path))
	{
		ft_putstr_fd("Error\nInvalid north texture path\n", 2);
		return (FAILED);
	}
	if (!is_valid_texture_path(cub->parser.south_texture_path))
	{
		ft_putstr_fd("Error\nInvalid south texture path\n", 2);
		return (FAILED);
	}
	if (!is_valid_texture_path(cub->parser.west_texture_path))
	{
		ft_putstr_fd("Error\nInvalid west texture path\n", 2);
		return (FAILED);
	}
	if (!is_valid_texture_path(cub->parser.east_texture_path))
	{
		ft_putstr_fd("Error\nInvalid east texture path\n", 2);
		return (FAILED);
	}
	return (SUCCESS);
}

bool	validate_assets(t_cub *cub)
{
	if (validate_textures(cub) == FAILED)
		return (FAILED);
	if (!cub->parser.floor_color.valid || !cub->parser.ceiling_color.valid)
	{
		ft_putstr_fd("Error\nInvalid floor or ceiling color\n", 2);
		return (FAILED);
	}
	return (SUCCESS);
}
