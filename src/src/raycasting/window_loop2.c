/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_loop2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:58:29 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/25 14:15:59 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_cub *cub)
{
	handle_player_input(cub);
	ray_casting(cub);
	if (cub->window.window_init && cub->window.window_display && cub->image.img)
		mlx_put_image_to_window(cub->window.window_init,
			cub->window.window_display, cub->image.img, 0, 0);
	return (0);
}
