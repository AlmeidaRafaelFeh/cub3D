/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:02:30 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/08/06 15:48:59 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define COLOR_NORTH 0x0066FF  /* Azul forte */
#define COLOR_SOUTH 0xFF0000  /* Vermelho */
#define COLOR_EAST  0x00CC44  /* Verde */
#define COLOR_WEST  0xCC00FF  /* Magenta */

static int	get_wall_color(t_ray ray)
{
	if (ray.side == 1)
	{
		if (ray.dir_y > 0)
			return (COLOR_SOUTH);
		return (COLOR_NORTH);
	}
	if (ray.dir_x > 0)
		return (COLOR_WEST);
	return (COLOR_EAST);
}

static void	get_wall_bounds(double perp_dist, int *start, int *end)
{
	int	line_height;

	if (perp_dist < 0.0001)
		perp_dist = 0.0001;
	line_height = (int)(SCREEN_H / perp_dist);
	*start = SCREEN_H / 2 - line_height / 2;
	*end = SCREEN_H / 2 + line_height / 2;
	if (*start < 0)
		*start = 0;
	if (*end >= SCREEN_H)
		*end = SCREEN_H - 1;
}

static void	draw_wall_column(t_game *game, int x, t_ray ray)
{
	int	start;
	int	end;
	int	y;
	int	color;

	get_wall_bounds(ray.perp_dist, &start, &end);
	color = get_wall_color(ray);
	y = start;
	while (y <= end)
	{
		my_pixel_put(&game->screen, x, y, color);
		y++;
	}
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
