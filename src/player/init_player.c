/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:00:21 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/08/03 by tmfanfa                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// direção/plano da câmera para cada orientação lida do .cub
// -> dir_x/dir_y  -> para onde o jogador olha
// -> plane_x/plane_y -> plano da câmera, perpendicular à direção (define o FOV)
static void	set_direction(t_player *player)
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
	else if (player->orientation == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
	else
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
}

// posição e direção iniciais do jogador.
// x/y já vêm preenchidos pelo parsing (índice da coluna/linha do mapa
// onde estava o N/S/E/W); aqui a gente só centraliza no meio do tile.
void	init_player(t_player *player)
{
	player->x = player->x + 0.5;
	player->y = player->y + 0.5;
	set_direction(player);
}
