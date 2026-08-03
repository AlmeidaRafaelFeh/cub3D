/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:02:51 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/07/29 15:43:19 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// aqui monta o raio da coluna "x" da tela, assim:
// - camera_x vai de -1 (borda esquerda) a +1 (borda direita)
// - dir_x/dir_y = direção do player + plano de câmera * camera_x
// - map_x/map_y = lugar do mapa (célula) onde o player está agora
// - delta_dist = distância (em células) para atravessar uma celula inteira
//   andando em X ou em Y
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

// define pra X e pra Y:
// -> step: se o raio anda +1 ou -1 célula
// -> side_dist: distância até a primeira linha de grade encontrada
// "começo" do DDA (Digital Differential Analysis)
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

// anda célula por célula no mapa (sempre para a celula vizinha mais
// próxima em X ou em Y) até encontrar uma parede '1'
// ray->side guarda se a parede foi atingida numa linha vertical (0)
// ou horizontal (1) da grade (que vai ser usado depois para escolher a cor/textura)
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

// distância perpendicular entre o player e a parede atingida
// usa a distância perpendicular (e não a distância real do raio) evita
// o efeito "olho de peixe" na projecao 3D
static double	get_perp_distance(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	return (ray->side_dist_y - ray->delta_dist_y);
}

// funçaoo principal -> monta e lança o raio da coluna "x", faz o DDA para
// achar a parede, e guarda a distância perpendicular no raio
t_ray	cast_ray(t_game *game, int x)
{
	t_ray	ray;

	ray = init_ray(game, x);
	setup_dda_steps(game, &ray);
	perform_dda(game, &ray);
	ray.perp_dist = get_perp_distance(&ray);
	return (ray);
}
