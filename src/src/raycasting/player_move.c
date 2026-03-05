/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:57:48 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/26 12:22:23 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_slide(t_cub *cub, t_slide_data *data)
{
	int	gx_cur;
	int	gy_cur;

	gy_cur = (int)cub->player.pos_y;
	gx_cur = (int)cub->player.pos_x;
	try_x_slide(cub, data->new_x, gy_cur, data->gx);
	try_y_slide(cub, data->new_y, data->gy, gx_cur);
}

static void	apply_movement(t_cub *cub, double move_x, double move_y)
{
	t_slide_data	data;
	double			new_x;
	double			new_y;
	int				grid_x;
	int				grid_y;

	new_x = cub->player.pos_x + move_x;
	new_y = cub->player.pos_y + move_y;
	grid_x = (int)new_x;
	grid_y = (int)new_y;
	if (check_basic_collision(cub, grid_x, grid_y) == 0)
	{
		cub->player.pos_x = new_x;
		cub->player.pos_y = new_y;
		return ;
	}
	data.new_x = new_x;
	data.new_y = new_y;
	data.gx = grid_x;
	data.gy = grid_y;
	handle_slide(cub, &data);
}

void	move_player(t_cub *cub, int direction)
{
	double	move_x;
	double	move_y;

	move_x = cub->player.dir_x * MOVE_SPEED * direction;
	move_y = cub->player.dir_y * MOVE_SPEED * direction;
	apply_movement(cub, move_x, move_y);
}

void	strafe_player(t_cub *cub, int direction)
{
	double	move_x;
	double	move_y;

	move_x = -cub->player.dir_y * MOVE_SPEED * direction;
	move_y = cub->player.dir_x * MOVE_SPEED * direction;
	apply_movement(cub, move_x, move_y);
}
