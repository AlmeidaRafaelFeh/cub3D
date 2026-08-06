/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:02:51 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/08/06 10:55:52 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_ray	init_ray(t_game *game, int x)
{
	t_ray	ray;
	double	camera_x;

	camera_x = 2.0 * x / (double)SCREEN_W - 1.0;
	ray.dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	ray.dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	ray.map_x = (int)game->player.x;
	ray.map_y = (int)game->player.y;
	ray.delta_dist_x = fabs(1.0 / ray.dir_x);
	ray.delta_dist_y = fabs(1.0 / ray.dir_y);
	return (ray);
}

static void	setup_dda_steps(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y)
			* ray->delta_dist_y;
	}
}

static void	perform_dda(t_game *game, t_ray *ray)
{
	while (game->map[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}

static double	get_perp_distance(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	return (ray->side_dist_y - ray->delta_dist_y);
}

t_ray	cast_ray(t_game *game, int x)
{
	t_ray	ray;

	ray = init_ray(game, x);
	setup_dda_steps(game, &ray);
	perform_dda(game, &ray);
	ray.perp_dist = get_perp_distance(&ray);
	return (ray);
}
