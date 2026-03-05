/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:57:42 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/26 11:56:38 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north_orientation(t_cub *cub)
{
	cub->player.dir_x = -1;
	cub->player.dir_y = 0;
	cub->player.plane_x = 0;
	cub->player.plane_y = tan((FOV * M_PI / 180) / 2);
}

static void	set_south_orientation(t_cub *cub)
{
	cub->player.dir_x = 1;
	cub->player.dir_y = 0;
	cub->player.plane_x = 0;
	cub->player.plane_y = -tan((FOV * M_PI / 180) / 2);
}

static void	set_east_orientation(t_cub *cub)
{
	cub->player.dir_x = 0;
	cub->player.dir_y = 1;
	cub->player.plane_x = -tan((FOV * M_PI / 180) / 2);
	cub->player.plane_y = 0;
}

static void	set_west_orientation(t_cub *cub)
{
	cub->player.dir_x = 0;
	cub->player.dir_y = -1;
	cub->player.plane_x = tan((FOV * M_PI / 180) / 2);
	cub->player.plane_y = 0;
}

void	init_player(t_cub *cub)
{
	if (cub->player.orientation == 'N')
		set_north_orientation(cub);
	else if (cub->player.orientation == 'S')
		set_south_orientation(cub);
	else if (cub->player.orientation == 'E')
		set_east_orientation(cub);
	else if (cub->player.orientation == 'W')
		set_west_orientation(cub);
}
