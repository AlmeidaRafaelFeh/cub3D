/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 08:58:37 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/02 15:12:29 by rafreire         ###   ########.fr       */
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
# include "libft.h"
# include "get_next_line.h"

# define SCREEN_W 1280
# define SCREEN_H 720

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef t_img	t_pixel_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_w;
	int			map_h;
	t_img		screen;
	t_player	player;
}	t_game;

typedef struct s_flood
{
	char	**map;
	int		width;
	int		height;
}	t_flood;

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

int		render_main(void);
int		render_frame(t_game *game);
void	render_background(t_game *game);
void	render_minimap(t_game *game);

// parsing functions

void	free_map(t_game *game);
int		is_valid_char(char c);
int		parsing_main(char *file_path);
int		parse_map_from_rows(char **rows, int row_count, t_game *game);
int		get_max_width(char **rows, int row_count);
int		get_row_len(char *row);
int		set_player_position(t_game *game, int x, int y);
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

// utils mlx
void	my_pixel_put(t_img *img, int x, int y, int color);

#endif
