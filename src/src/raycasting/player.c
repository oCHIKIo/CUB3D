/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:57:53 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/25 14:15:55 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub *cub, int direction)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = -ROTATION_SPEED * direction;
	old_dir_x = cub->player.dir_x;
	old_plane_x = cub->player.plane_x;
	cub->player.dir_x = cub->player.dir_x * cos(angle) - cub->player.dir_y
		* sin(angle);
	cub->player.dir_y = old_dir_x * sin(angle) + cub->player.dir_y * cos(angle);
	cub->player.plane_x = cub->player.plane_x * cos(angle) - cub->player.plane_y
		* sin(angle);
	cub->player.plane_y = old_plane_x * sin(angle) + cub->player.plane_y
		* cos(angle);
}
