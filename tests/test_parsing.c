#include <assert.h>
#include "cub3D.h"

int	main(void)
{
	t_game	game;
	char	*rows[] = {"111", "10", "1N1"};

	memset(&game, 0, sizeof(game));
	assert(parse_map_from_rows(rows, 3, &game) == 0);
	assert(game.map_h == 3);
	assert(game.map_w == 3);
	assert(game.map[1][2] == '0');
	assert(game.map[2][1] == '0');
	assert(game.map[2][2] == '1');
	return (0);
}
