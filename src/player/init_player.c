/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:34:53 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/27 15:41:12 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	direction_s_e(t_player *player)
{
	if (player->orientation == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
	else if (player->orientation == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = 0.66;
	}
}

static void	direction_n_w(t_player *player)
{
	if (player->orientation == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
	else if (player->orientation == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
}

static void	set_direction(t_player *player)
{
	if (player->orientation == 'N' || player->orientation == 'W')
	{
		direction_n_w(player);
	}
	else if (player->orientation == 'S' || player->orientation == 'E')
	{
		direction_s_e(player);
	}
}

void	init_player(t_player *player)
{
	player->x = player->x + 0.5;
	player->y = player->y + 0.5;
	set_direction(player);
}
