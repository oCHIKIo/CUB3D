/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:20:55 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 11:41:09 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"

bool	is_player_position(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'W')
		return (true);
	return (false);
}

void	set_player_position(t_cub *cub, int i, int j)
{
	if (!cub->parser.map_grid || !cub->parser.map_grid[i])
		return ;
	cub->player.pos_x = j + 0.5;
	cub->player.pos_y = i + 0.5;
	cub->player.orientation = cub->parser.map_grid[i][j];
	cub->parser.map_grid[i][j] = '0';
}

char	get_char_at(t_cub *cub, int y, int x)
{
	if (y < 0 || y >= cub->parser.map_height)
		return (' ');
	if (x < 0 || x >= cub->parser.map_width[y])
		return (' ');
	return (cub->parser.map_grid[y][x]);
}

bool	check_cell_neighbors(t_cub *cub, int i, int j)
{
	if (get_char_at(cub, i - 1, j) == ' ')
		return (false);
	if (get_char_at(cub, i + 1, j) == ' ')
		return (false);
	if (get_char_at(cub, i, j - 1) == ' ')
		return (false);
	if (get_char_at(cub, i, j + 1) == ' ')
		return (false);
	return (true);
}

bool	check_walls_closed(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->parser.map_height)
	{
		j = 0;
		while (j < cub->parser.map_width[i])
		{
			if (cub->parser.map_grid[i][j] == '0')
			{
				if (!check_cell_neighbors(cub, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
