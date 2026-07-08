/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 08:58:37 by rafreire          #+#    #+#             */
/*   Updated: 2026/07/08 09:12:37 by rafreire         ###   ########.fr       */
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

# define SCREEN_W 1280
# define SCREEN_H 720

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_flood
{
	char	**map;
	int		width;
	int		height;
}	t_flood;

typedef struct s_pixel_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} 	t_pixel_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_w;
	int			map_h;
	int			player_count;
	int			exit_count;
	int			collect_count;
	int			player_x;
	int			player_y;
	void		*img_wall;
	void		*img_floor;
	void		*img_player;
	void		*img_exit;
	t_player	player;
}	t_game;

int		parsing_main(void);
int		render_main(void);
void	my_pixel_put(t_pixel_data *data, int x, int y, int color);


#endif