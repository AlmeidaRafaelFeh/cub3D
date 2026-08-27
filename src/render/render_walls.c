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

	if (!tex || !tex->addr || x < 0 || x >= tex->width || y < 0 || y >= tex->height)
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

static void	draw_wall_column(t_game *game, int x, t_ray ray)
{
	t_texture	*tex;
	int			bounds[2];
	int			tex_x;
	int			tex_y;
	int			y;
	double		step;
	double		tex_pos;
	int			lh;

	get_wall_bounds(ray.perp_dist, &bounds[0], &bounds[1]);
	tex = get_wall_texture(game, ray, &tex_x);
	lh = (int)(SCREEN_H / ray.perp_dist);
	step = 1.0 * tex->height / lh;
	tex_pos = (bounds[0] - SCREEN_H / 2.0 + lh / 2.0) * step;
	y = bounds[0];
	while (y <= bounds[1])
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		tex_pos += step;
		my_pixel_put(&game->screen, x, y, get_tex_pixel(tex, tex_x, tex_y));
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
