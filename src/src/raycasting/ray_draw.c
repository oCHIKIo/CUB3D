/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:58:05 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/25 14:26:55 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_cub *cub, t_draw_ctx *ctx, int end)
{
	int	y;

	if (!ctx || !ctx->base)
		return ;
	y = 0;
	while (y < end)
	{
		*(unsigned int *)(ctx->base + y
				* ctx->stride) = (unsigned int)cub->ceiling_color;
		y++;
	}
}

void	draw_textured_wall(t_cub *cub, t_ray *ray, t_draw_ctx *ctx, int tex_num)
{
	int		y;
	double	step;
	double	tex_pos;

	if (!ray || !ctx || !ctx->base)
		return ;
	y = ray->draw_start;
	step = 1.0 * TEXTURE_SIZE / ray->line_height;
	tex_pos = (ray->draw_start - ctx->height / 2 + ray->line_height / 2) * step;
	while (y <= ray->draw_end && y < ctx->height)
	{
		ray->tex_y = (int)tex_pos & (TEXTURE_SIZE - 1);
		tex_pos += step;
		*(unsigned int *)(ctx->base + y * ctx->stride)
			= (unsigned int)get_pixel_color(&cub->textures[tex_num],
				ray->tex_x, ray->tex_y);
		y++;
	}
}

void	draw_floor(t_cub *cub, t_draw_ctx *ctx, int start)
{
	int	y;

	if (!ctx || !ctx->base)
		return ;
	y = start;
	while (y < ctx->height)
	{
		*(unsigned int *)(ctx->base + y
				* ctx->stride) = (unsigned int)cub->floor_color;
		y++;
	}
}
