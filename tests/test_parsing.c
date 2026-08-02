#include <assert.h>
#include "cub3D.h"

int	main(void)
{
	t_game	game;
	char	*rows[] = {"1111", "1N01", "1111"};

	memset(&game, 0, sizeof(game));
	assert(parse_map_from_rows(rows, 3, &game) == 0);
	assert(game.map_h == 3);
	assert(game.map_w == 4);
	assert(game.player.x == 1);
	assert(game.player.y == 1);
	assert(game.player.direction == 'N');
	assert(game.map[1][1] == '0');
	assert(game.map[1][2] == '0');
	assert(game.map[0][0] == '1');
	assert(game.map[2][3] == '1');
	return (0);
}
