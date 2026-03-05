/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:57:59 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/26 13:58:19 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	step_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static int	check_hit(t_cub *cub, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_x < 0)
		return (1);
	if (ray->map_y >= cub->parser.map_height)
		return (1);
	if (!cub->parser.map_width || !cub->parser.map_grid)
		return (1);
	if (ray->map_x >= cub->parser.map_width[ray->map_y])
		return (1);
	if (!cub->parser.map_grid[ray->map_y])
		return (1);
	if (cub->parser.map_grid[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

void	perform_dda(t_cub *cub, t_ray *ray)
{
	int	steps;
	int	max_steps;

	if (!ray)
		return ;
	steps = 0;
	max_steps = cub->parser.map_height + cub->window.window_width;
	while (ray->hit == 0 && steps < max_steps)
	{
		step_ray(ray);
		steps++;
		if (check_hit(cub, ray))
			ray->hit = 1;
	}
}

static void	calculate_perp_distance(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
	{
		if (ray->dir_x == 0)
			ray->perp_wall_dist = 1e30;
		else
			ray->perp_wall_dist = (ray->map_x - player->pos_x + (1
						- ray->step_x) / 2) / ray->dir_x;
	}
	else
	{
		if (ray->dir_y == 0)
			ray->perp_wall_dist = 1e30;
		else
			ray->perp_wall_dist = (ray->map_y - player->pos_y + (1
						- ray->step_y) / 2) / ray->dir_y;
	}
	if (ray->perp_wall_dist == 0)
		ray->perp_wall_dist = 0.0001;
}

void	calculate_wall_distance(t_ray *ray, t_player *player, int height)
{
	if (!ray || !player)
		return ;
	calculate_perp_distance(ray, player);
	ray->line_height = (int)(height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + height / 2;
	if (ray->draw_end >= height)
		ray->draw_end = height - 1;
}
