/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:32 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 14:16:50 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"

static int	in_bounds(int x, int y, int w, int h)
{
	return (x >= 0 && y >= 0 && x < w && y < h);
}

void	draw_pixel(t_image *image, int x, int y, int color)
{
	int		bpp_bytes;
	char	*dst;

	if (!image || !image->addr)
		return ;
	bpp_bytes = image->bpp / 8;
	if (bpp_bytes <= 0)
		return ;
	if (!in_bounds(x, y, WIDTH, HEIGHT))
		return ;
	dst = image->addr + (y * image->size_line + x * bpp_bytes);
	*(unsigned int *)dst = (unsigned int)color;
}

int	get_pixel_color(t_texture *texture, int x, int y)
{
	int		bpp_bytes;
	char	*src;

	if (!texture || !texture->addr)
		return (0);
	bpp_bytes = texture->bpp / 8;
	if (bpp_bytes <= 0)
		return (0);
	if (!in_bounds(x, y, texture->width, texture->height))
		return (0);
	src = texture->addr + (y * texture->size_line + x * bpp_bytes);
	return (*(unsigned int *)src);
}

bool	load_texture(t_cub *cub, t_texture *texture, char *path)
{
	if (!texture || !path)
		return (false);
	texture->img = mlx_xpm_file_to_image(cub->window.window_init, path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		ft_putstr_fd("Error: Failed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (false);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->addr)
	{
		ft_putstr_fd("Error: Failed to get texture data address\n", 2);
		return (false);
	}
	return (true);
}

bool	load_textures(t_cub *cub)
{
	if (!load_texture(cub, &cub->textures[NORTH],
			cub->parser.north_texture_path))
		return (false);
	if (!load_texture(cub, &cub->textures[SOUTH],
			cub->parser.south_texture_path))
		return (false);
	if (!load_texture(cub, &cub->textures[EAST], cub->parser.east_texture_path))
		return (false);
	if (!load_texture(cub, &cub->textures[WEST], cub->parser.west_texture_path))
		return (false);
	return (true);
}
