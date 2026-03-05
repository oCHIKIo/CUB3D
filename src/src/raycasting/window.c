/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:58:35 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/26 11:53:01 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_window(t_cub *cub)
{
	cub->window.window_init = mlx_init();
	if (!cub->window.window_init)
		return (false);
	cub->window.window_width = WIDTH;
	cub->window.window_height = HEIGHT;
	cub->window.window_display = mlx_new_window(cub->window.window_init,
			cub->window.window_width, cub->window.window_height, "cub3D");
	if (!cub->window.window_display)
		return (false);
	cub->image.img = mlx_new_image(cub->window.window_init, WIDTH, HEIGHT);
	cub->image.addr = mlx_get_data_addr(cub->image.img, &cub->image.bpp,
			&cub->image.size_line, &cub->image.endian);
	return (true);
}

int	close_window(t_cub *cub)
{
	free_resources(cub);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		cub->key_w = 1;
	else if (keycode == KEY_A)
		cub->key_a = 1;
	else if (keycode == KEY_S)
		cub->key_s = 1;
	else if (keycode == KEY_D)
		cub->key_d = 1;
	else if (keycode == KEY_LEFT)
		cub->key_left = 1;
	else if (keycode == KEY_RIGHT)
		cub->key_right = 1;
	else if (keycode == KEY_ESC)
		close_window(cub);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		cub->key_w = 0;
	else if (keycode == KEY_A)
		cub->key_a = 0;
	else if (keycode == KEY_S)
		cub->key_s = 0;
	else if (keycode == KEY_D)
		cub->key_d = 0;
	else if (keycode == KEY_LEFT)
		cub->key_left = 0;
	else if (keycode == KEY_RIGHT)
		cub->key_right = 0;
	return (0);
}
