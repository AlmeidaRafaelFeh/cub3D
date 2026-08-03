/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 08:58:37 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/03 by tmfanfa                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define SCREEN_W 1280
# define SCREEN_H 720

// códigos de tecla (X11 keysym, usados pela MLX no Linux) e de
// evento de janela, usados nos hooks de teclado/fechar
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define EVENT_KEY_PRESS	2
# define EVENT_KEY_RELEASE	3

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moves;
	char	orientation;
}	t_player;

typedef struct s_img //image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// t_keys: pra guardar quando pressiona a tecla ou solta ela
// quando a gente atualiza o movimento frame a frame ele fica mais suave e não tão travado
typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_game // game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	char		**map;
	int			map_w;
	int			map_h;
	t_player	player;
	t_keys		keys;

}	t_game;

typedef struct s_flood
{
	char	**map;
	int		width;
	int		height;
}	t_flood;

// aqui foi meio vibe coding, porque tem bastante ângulo e raio pra calcular
// mas deixei também comentado as funções pra mais ou menos entender como cada
// um foi calculado pra ajudar na visualização e movimento do player
typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_dist;
}	t_ray;

// t_scene: dados brutos lidos do arquivo .cub (texturas, cores, linhas
// do mapa) antes de virarem o game->map final. Usado só durante o parsing.
typedef struct s_scene
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceiling_color;
	char	**rows;
	int		row_count;
}	t_scene;

int		parsing_main(char *file_path, t_game *game);
int		render_main(t_game *game);
int		render_frame(t_game *game);
void	render_background(t_game *game);
void	render_walls(t_game *game);
void	render_minimap(t_game *game);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	init_player(t_player *player);
t_ray	cast_ray(t_game *game, int x);
void	init_keys(t_keys *keys);
void	set_hooks(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	update_player(t_game *game);
void	move_player(t_game *game);
void	rotate_player(t_game *game);

// parsing functions (Rafael)
void	free_map(t_game *game);
int		is_valid_char(char c);
int		parse_map_from_rows(char **rows, int row_count, t_game *game);
int		get_max_width(char **rows, int row_count);
int		get_row_len(char *row);
int		set_player_position(t_game *game, int x, int y, char orientation);
int		count_players(char **rows, int row_count);
int		is_blank_line(char *line);
void	normalize_line(char *line);
int		is_header_line(char *line);
int		is_map_line(char *line);
char	*skip_spaces(char *line);
int		header_complete(t_scene *scene);
int		store_header_line(t_scene *scene, char *line);
int		append_row(t_scene *scene, char *line);
int		collect_scene_data(int fd, t_scene *scene);
void	free_scene_data(t_scene *scene);
char	**alloc_map(int row_count, int max_width);

#endif
