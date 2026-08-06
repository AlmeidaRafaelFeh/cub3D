/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:02:30 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/08/03 20:52:08 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// as cores tão meio feias hehe, mas são cores provisórias
// uma por "face" da parede (norte/sul/leste/oeste)
// servem só pra gente enxergar a profundidade e orientaçãoo antes de termos
// as texturas de verdade (que ainda não sei qual tema vai ser hehe)
// cada define aqui vai virar uma textura usando mlx_xpm_file_to_image pra carregar elas mais pra frente
# define COLOR_NORTH 0x0066FF  /* Azul forte */
# define COLOR_SOUTH 0xFF0000  /* Vermelho */
# define COLOR_EAST  0x00CC44  /* Verde */
# define COLOR_WEST  0xCC00FF  /* Magenta */

// escolhe a cor da parede de acordo com o lado atingido pelo raio
// ray.side == 1 -> parede "horizontal" (norte ou sul), diferenciada pelo sinal de dir_y.
// ray.side == 0 -> parede "vertical" (Leste ou Oeste), diferenciada pelo sinal de dir_x.
static int	get_wall_color(t_ray ray)
{
	if (ray.side == 1)
	{
		if (ray.dir_y > 0)
			return (COLOR_NORTH);
		return (COLOR_SOUTH);
	}
	if (ray.dir_x > 0)
		return (COLOR_WEST);
	return (COLOR_EAST);
}

// calcula, a partir da distância perpendicular do raio, em que pixel
// (do eixo Y) a parede começaa e termina naquela coluna da tela
// -> quanto menor a distância, maior (mais altura terá) a parede na tela
// Os "if" no final so limitam o desenho aos limites da tela, caso a
// parede fique tão alta que passe do topo/da base
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

// desenha a coluna de parede "x" na tela, do pixel start até end,
// todos com a mesma cor (definida pela face atingida)
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

// percorre cada coluna da tela, lança um raio para ela (cast_ray, já
// pronto no raycasting.c) e desenha a fatia de parede correspondente
// chamada a cada frame, depois do render_background (céu/chão) e
// antes do render_minimap (que fica por cima de tudo)
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
