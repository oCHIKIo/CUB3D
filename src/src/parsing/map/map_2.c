/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:02 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 11:10:43 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"

bool	validate_map_characters(t_cub *cub)
{
	int	i;

	if (!cub->parser.map_grid)
		return (FAILED);
	i = 0;
	while (i < cub->parser.map_height)
	{
		if (!cub->parser.map_grid[i])
		{
			i++;
			continue ;
		}
		if (!validate_row_chars(cub, i))
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

bool	validate_map(t_cub *cub)
{
	int	i;
	int	j;

	if (!cub->parser.map_file_lines)
		return (FAILED);
	i = cub->parser.load_map.index;
	while (cub->parser.map_file_lines[i])
	{
		j = 0;
		while (cub->parser.map_file_lines[i][j])
		{
			if (!ft_isspace(cub->parser.map_file_lines[i][j]))
			{
				ft_putstr_fd(
					"Error\nInvalid lines detected after map section\n",
					2);
				return (FAILED);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static bool	allocate_map_memory(t_cub *cub, char **lines)
{
	int	current_line;

	if (!lines)
		return (FAILED);
	while (lines[cub->parser.load_map.index]
		&& is_empty_string(lines[cub->parser.load_map.index]))
		cub->parser.load_map.index++;
	current_line = cub->parser.load_map.index;
	while (lines[current_line] && *lines[current_line])
	{
		cub->parser.map_height++;
		current_line++;
	}
	cub->parser.map_width = ft_malloc(sizeof(int) * cub->parser.map_height);
	cub->parser.map_grid = ft_malloc(sizeof(char *) * (cub->parser.map_height
				+ 1));
	return (SUCCESS);
}

static void	copy_map_data(t_cub *cub, char **lines)
{
	int	i;

	i = 0;
	while (lines[cub->parser.load_map.index]
		&& *lines[cub->parser.load_map.index])
	{
		cub->parser.map_grid[i] = lines[cub->parser.load_map.index];
		cub->parser.map_width[i] = ft_strlen(lines[cub->parser.load_map.index]);
		cub->parser.load_map.index++;
		i++;
	}
	cub->parser.map_grid[i] = NULL;
}

bool	assign_map_grid(t_cub *cub)
{
	char	**lines;

	lines = cub->parser.map_file_lines;
	if (allocate_map_memory(cub, lines) == FAILED)
		return (FAILED);
	copy_map_data(cub, lines);
	if (validate_map_characters(cub) == FAILED)
		return (FAILED);
	return (validate_map(cub));
}
