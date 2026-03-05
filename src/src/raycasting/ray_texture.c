/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:58:16 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/26 12:13:35 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	determine_texture(t_ray *ray)
{
	if (!ray)
		return (NORTH);
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->step_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void	calculate_texture_x(t_ray *ray, t_player *player)
{
	if (!ray || !player)
		return ;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEXTURE_SIZE);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tex_x = TEXTURE_SIZE - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tex_x = TEXTURE_SIZE - ray->tex_x - 1;
}

void	draw_vertical_line(t_cub *cub, t_ray *ray, int x, int texture_num)
{
	int			bpp;
	t_draw_ctx	ctx;

	if (!ray || !cub->image.addr)
		return ;
	ctx.height = cub->window.window_height;
	bpp = cub->image.bpp / 8;
	ctx.stride = cub->image.size_line;
	ctx.base = cub->image.addr + x * bpp;
	draw_ceiling(cub, &ctx, ray->draw_start);
	draw_textured_wall(cub, ray, &ctx, texture_num);
	draw_floor(cub, &ctx, ray->draw_end + 1);
}
