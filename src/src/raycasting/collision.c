/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:57:16 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/25 14:16:57 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_position(t_cub *cub, int gx, int gy)
{
	if (!cub->parser.map_width || !cub->parser.map_grid)
		return (0);
	if (gy < 0 || gy >= cub->parser.map_height)
		return (0);
	if (gx < 0 || gx >= cub->parser.map_width[gy])
		return (0);
	if (!cub->parser.map_grid[gy])
		return (0);
	return (1);
}

int	check_basic_collision(t_cub *cub, int gx, int gy)
{
	if (!is_valid_position(cub, gx, gy))
		return (1);
	if (cub->parser.map_grid[gy][gx] != '1')
		return (0);
	return (1);
}

void	try_x_slide(t_cub *cub, double cand_x, int gy_cur, int gx)
{
	if (!is_valid_position(cub, gx, gy_cur))
		return ;
	if (cub->parser.map_grid[gy_cur][gx] != '1')
		cub->player.pos_x = cand_x;
}

void	try_y_slide(t_cub *cub, double cand_y, int gy, int gx_cur)
{
	if (!is_valid_position(cub, gx_cur, gy))
		return ;
	if (cub->parser.map_grid[gy][gx_cur] != '1')
		cub->player.pos_y = cand_y;
}
