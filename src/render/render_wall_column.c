/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_column.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:00:00 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/27 19:28:30 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_texture	*get_wall_texture(t_game *game, t_ray ray, int *tex_x)
{
	t_texture	*tex;
	double		wall_x;

	if (ray.side == 1 && ray.dir_y > 0)
		tex = &game->north;
	else if (ray.side == 1)
		tex = &game->south;
	else if (ray.dir_x > 0)
		tex = &game->west;
	else
		tex = &game->east;
	if (ray.side == 0)
		wall_x = game->player.y + ray.perp_dist * ray.dir_y;
	else
		wall_x = game->player.x + ray.perp_dist * ray.dir_x;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * (double)tex->width);
	if ((ray.side == 0 && ray.dir_x > 0) || (ray.side == 1 && ray.dir_y < 0))
		*tex_x = tex->width - *tex_x - 1;
	return (tex);
}

static unsigned int	get_tex_pixel(t_texture *tex, int x, int y)
{
	char	*dst;

	if (!tex || !tex->addr)
		return (0);
	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
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

void	init_col_draw(t_game *game, t_ray ray, t_col_draw *col)
{
	int	lh;

	get_wall_bounds(ray.perp_dist, &col->start, &col->end);
	col->tex = get_wall_texture(game, ray, &col->tex_x);
	lh = (int)(SCREEN_H / ray.perp_dist);
	col->step = 1.0 * col->tex->height / lh;
	col->tex_pos = (col->start - SCREEN_H / 2.0 + lh / 2.0) * col->step;
}

void	paint_wall_column(t_game *game, int x, t_col_draw *col)
{
	int	y;
	int	tex_y;
	int	color;

	y = col->start;
	while (y <= col->end)
	{
		tex_y = (int)col->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= col->tex->height)
			tex_y = col->tex->height - 1;
		col->tex_pos += col->step;
		color = get_tex_pixel(col->tex, col->tex_x, tex_y);
		my_pixel_put(&game->screen, x, y, color);
		y++;
	}
}
