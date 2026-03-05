/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:19:47 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 10:49:53 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"
#include "../parser.h"

static void	convert_rgb_values(char **rgb_values, t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	while (*rgb_values[0])
		r = r * 10 + (*rgb_values[0]++ - '0');
	while (*rgb_values[1])
		g = g * 10 + (*rgb_values[1]++ - '0');
	while (*rgb_values[2])
		b = b * 10 + (*rgb_values[2]++ - '0');
	color->r = r;
	color->g = g;
	color->b = b;
	color->valid = true;
}

static bool	parse_rgb(t_color *color, char *rgb_str)
{
	char	**rgb_values;

	rgb_values = ft_split(rgb_str, ',');
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2]
		|| rgb_values[3])
		return (false);
	while (*rgb_values[0] && ft_isspace(*rgb_values[0]))
		rgb_values[0]++;
	while (*rgb_values[1] && ft_isspace(*rgb_values[1]))
		rgb_values[1]++;
	while (*rgb_values[2] && ft_isspace(*rgb_values[2]))
		rgb_values[2]++;
	if (!is_valid_rgb_value(rgb_values[0]) || !is_valid_rgb_value(rgb_values[1])
		|| !is_valid_rgb_value(rgb_values[2]))
		return (false);
	convert_rgb_values(rgb_values, color);
	return (true);
}

static bool	assign_floor_color(t_cub *cub, char **chunks)
{
	if (ft_strcmp(chunks[0], "F") == 0)
	{
		if (cub->parser.floor_color.valid)
			return (FAILED);
		if (!parse_rgb(&cub->parser.floor_color, chunks[1]))
			return (FAILED);
		return (SUCCESS);
	}
	return (FAILED);
}

static bool	assign_ceiling_color(t_cub *cub, char **chunks)
{
	if (ft_strcmp(chunks[0], "C") == 0)
	{
		if (cub->parser.ceiling_color.valid)
			return (FAILED);
		if (!parse_rgb(&cub->parser.ceiling_color, chunks[1]))
			return (FAILED);
		return (SUCCESS);
	}
	return (FAILED);
}

int	assign_colors(t_cub *cub, char **chunks)
{
	if (assign_floor_color(cub, chunks) == SUCCESS || assign_ceiling_color(cub,
			chunks) == SUCCESS)
		return (SUCCESS);
	return (FAILED);
}
