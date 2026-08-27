/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:02:30 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/08/27 19:28:43 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_wall_column(t_game *game, int x, t_ray ray)
{
	t_col_draw	col;

	init_col_draw(game, ray, &col);
	paint_wall_column(game, x, &col);
}

void	render_walls(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < SCREEN_W)
	{
		ray = cast_ray(game, x);
		draw_wall_column(game, x, ray);
		x++;
	}
}
