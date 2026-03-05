/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:57:29 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/25 11:57:29 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_hooks(t_cub *cub)
{
	mlx_hook(cub->window.window_display, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->window.window_display, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->window.window_display, 17, 1L << 17, close_window, cub);
	mlx_loop_hook(cub->window.window_init, game_loop, cub);
}

static void	set_defaults(t_cub *cub)
{
	ft_memset(cub, 0, sizeof(*cub));
	cub->ceiling_color = -1;
	cub->floor_color = -1;
}

static bool	initialize(t_cub *cub, char *path)
{
	if (parser(cub, path) == FAILED)
		return (false);
	if (!init_window(cub))
		return (false);
	if (!load_textures(cub))
		return (false);
	init_player(cub);
	return (true);
}

static void	start_loop(t_cub *cub)
{
	ray_casting(cub);
	mlx_put_image_to_window(cub->window.window_init, cub->window.window_display,
		cub->image.img, 0, 0);
	setup_hooks(cub);
	mlx_loop(cub->window.window_init);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	set_defaults(&cub);
	if (ac != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3D <map_path>\n", 2);
		return (1);
	}
	if (!initialize(&cub, av[1]))
	{
		free_resources(&cub);
		return (1);
	}
	start_loop(&cub);
	free_resources(&cub);
	return (0);
}
