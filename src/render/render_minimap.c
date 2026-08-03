/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:05:04 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/07/29 15:47:47 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define TILE_SIZE 16

// preenche o quadrado
static void	draw_square(t_game *game, int start_x, int start_y,	int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			my_pixel_put(&game->screen,	start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

// vai desenhar o mapa inteiro
void	render_minimap(t_game *game)
{
	draw_square(game, 20, 20, 0xFFFFFF); // para teste
	(void)game;
}
