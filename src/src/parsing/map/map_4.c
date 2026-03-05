/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:10 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 11:16:16 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"

bool	validate_row_chars(t_cub *cub, int i)
{
	int	j;

	j = 0;
	while (cub->parser.map_grid[i][j])
	{
		if (!is_valid_map_char(cub->parser.map_grid[i][j]))
		{
			ft_putstr_fd("Error\nInvalid character in map\n", 2);
			return (false);
		}
		j++;
	}
	return (true);
}

bool	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	if (c == 'N' || c == 'S')
		return (true);
	if (c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	process_player_row(t_cub *cub, t_fnd_plyr *x)
{
	x->j = 0;
	while (x->j < cub->parser.map_width[x->i])
	{
		if (is_player_position(cub->parser.map_grid[x->i][x->j]))
		{
			set_player_position(cub, x->i, x->j);
			x->player_count++;
		}
		x->j++;
	}
	return (true);
}

bool	find_player(t_cub *cub)
{
	t_fnd_plyr	x;

	if (!cub->parser.map_grid || !cub->parser.map_width)
		return (false);
	x.player_count = 0;
	x.i = 0;
	while (x.i < cub->parser.map_height)
	{
		if (!cub->parser.map_grid[x.i])
		{
			x.i++;
			continue ;
		}
		process_player_row(cub, &x);
		x.i++;
	}
	if (x.player_count != 1)
	{
		ft_putstr_fd("Error\nMap must contain exactly one player\n", 2);
		return (false);
	}
	return (true);
}

bool	load_and_validate_map(t_cub *cub)
{
	if (assign_map_grid(cub))
		return (true);
	if (!find_player(cub))
		return (true);
	if (!validate_map_closed(cub))
		return (true);
	return (false);
}
