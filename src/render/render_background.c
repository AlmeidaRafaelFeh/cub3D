/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 09:58:38 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/08/06 11:16:19 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
			my_pixel_put(&game->screen, x, y, game->ceiling_color);
			x++;
		}
		y++;
	}
}

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
			my_pixel_put(&game->screen, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}

void	render_background(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}
