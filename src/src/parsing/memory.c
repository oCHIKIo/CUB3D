/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:54 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:21:55 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

static void	free_textures(t_cub *cub)
{
	int	i;

	if (!cub->window.window_init)
		return ;
	i = 0;
	while (i < 4)
	{
		if (cub->textures[i].img)
			mlx_destroy_image(cub->window.window_init, cub->textures[i].img);
		i++;
	}
}

void	free_resources(t_cub *cub)
{
	free_textures(cub);
	if (cub->image.img && cub->window.window_init)
		mlx_destroy_image(cub->window.window_init, cub->image.img);
	if (cub->window.window_display && cub->window.window_init)
		mlx_destroy_window(cub->window.window_init, cub->window.window_display);
	if (cub->window.window_init)
	{
		mlx_destroy_display(cub->window.window_init);
		free(cub->window.window_init);
	}
	ft_free(SUCCESS);
}
