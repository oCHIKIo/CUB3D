/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:58:25 by bchiki            #+#    #+#             */
/*   Updated: 2025/11/25 14:16:17 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_player_input(t_cub *cub)
{
	int	rotation_input;

	rotation_input = 0;
	if (cub->key_w)
		move_player(cub, 1);
	if (cub->key_s)
		move_player(cub, -1);
	if (cub->key_a)
		strafe_player(cub, 1);
	if (cub->key_d)
		strafe_player(cub, -1);
	if (cub->key_left)
		rotation_input -= 1;
	if (cub->key_right)
		rotation_input += 1;
	if (rotation_input != 0)
		rotate_player(cub, rotation_input);
}
