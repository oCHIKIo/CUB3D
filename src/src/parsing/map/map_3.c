/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:07 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 11:42:15 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"

bool	flood_fill_check(t_cub *cub, int y, int x, char **visited)
{
	char	current;

	if (y < 0 || y >= cub->parser.map_height)
		return (false);
	if (x < 0 || x >= cub->parser.map_width[y])
		return (false);
	current = cub->parser.map_grid[y][x];
	if (current == ' ')
		return (false);
	if (current == '1')
		return (true);
	if (visited[y][x] == '1')
		return (true);
	visited[y][x] = '1';
	if (!flood_fill_check(cub, y - 1, x, visited))
		return (false);
	if (!flood_fill_check(cub, y + 1, x, visited))
		return (false);
	if (!flood_fill_check(cub, y, x - 1, visited))
		return (false);
	if (!flood_fill_check(cub, y, x + 1, visited))
		return (false);
	return (true);
}

void	init_visited(char **visited, int *map_width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < map_width[i])
		{
			visited[i][j] = '0';
			j++;
		}
		i++;
	}
}

char	**alloc_visited(t_cub *cub)
{
	char	**visited;
	int		i;

	visited = ft_malloc(sizeof(char *) * cub->parser.map_height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < cub->parser.map_height)
	{
		visited[i] = ft_malloc(sizeof(char) * cub->parser.map_width[i]);
		i++;
	}
	init_visited(visited, cub->parser.map_width, cub->parser.map_height);
	return (visited);
}

bool	run_flood_fill(t_cub *cub, char **visited)
{
	bool	result;
	int		player_y;
	int		player_x;

	player_y = (int)cub->player.pos_y;
	player_x = (int)cub->player.pos_x;
	result = flood_fill_check(cub, player_y, player_x, visited);
	if (!result)
	{
		ft_putstr_fd("Error\nMap is not closed by walls\n", 2);
		return (false);
	}
	return (true);
}

bool	validate_map_closed(t_cub *cub)
{
	char	**visited;

	if (!check_walls_closed(cub))
	{
		ft_putstr_fd("Error\nMap is not closed by walls\n", 2);
		return (false);
	}
	visited = alloc_visited(cub);
	if (!visited)
		return (false);
	if (!run_flood_fill(cub, visited))
		return (false);
	return (true);
}
