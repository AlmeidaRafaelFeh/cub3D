/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 09:58:38 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/07/29 15:43:34 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// metade superior da tela
// -> será a cor do teto <-
static void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_H / 2)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			my_pixel_put(&game->screen,	x, y, 0x87CEEB);
			x++;
		}
		y++;
	}
}


// metade inferior da tela
// -> será a cor do chão <-
static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = SCREEN_H / 2;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			my_pixel_put(&game->screen,	x, y, 0x555555);
			x++;
		}
		y++;
	}
}


// desenha céu e chão
void	render_background(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}
