/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:58:20 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/25 14:11:44 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_casting(t_cub *cub)
{
	t_ray	ray;
	int		x;
	int		texture_num;

	x = 0;
	while (x < cub->window.window_width)
	{
		init_ray(cub, &ray, x);
		calculate_step_and_side_dist(&ray, &cub->player);
		perform_dda(cub, &ray);
		calculate_wall_distance(&ray, &cub->player, cub->window.window_height);
		texture_num = determine_texture(&ray);
		calculate_texture_x(&ray, &cub->player);
		draw_vertical_line(cub, &ray, x, texture_num);
		x++;
	}
}
