/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:50:15 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 18:02:45 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "structure.h"
#include <string.h>

static bool	handle_mlx_hook(t_game *game)
{
	if (!game)
	{
		print_error ("GAME not found !\n");
		return (false);
	}
	mlx_hook(game->mlx.win, 6, 1L << 6, (void *)mouse_move, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, (void *)key_press, game);
	mlx_hook(game->mlx.win, 4, 1L << 2, (void *)mouse_press, game);
	mlx_hook(game->mlx.win, 3, 1L << 1, (void *)key_release, game);
	mlx_hook(game->mlx.win, 17, 0, (void *)close_window, game);
	return (true);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_malloc	*lst_malloc;

	lst_malloc = NULL;
	memset(&game, 0, sizeof(t_game));
	if (!parsing(&game, av, ac, &lst_malloc))
		return (1);
	game.lst_malloc = lst_malloc;
	if (!init_mlx(&game))
		return (free_lst_malloc(&lst_malloc), 1);
	game.prev_ms_x = WIN_WIDTH / 2;
	mlx_mouse_move(game.mlx.mlx,
		game.mlx.win,
		WIN_WIDTH / 2,
		WIN_HEIGHT / 2);
	if (!load_all_textures(&game))
		return (clean_mlx_and_malloc_lst(&game, &lst_malloc), 1);
	init_image(&game);
	game_loop_init(&game);
	game.last_time = get_time();
	if (!handle_mlx_hook (&game))
		return (clean_mlx_and_malloc_lst(&game, &lst_malloc), 1);
	mlx_loop_hook(game.mlx.mlx, (void *)game_loop, &game);
	mlx_loop(game.mlx.mlx);
	clean_mlx_and_malloc_lst(&game, &lst_malloc);
	return (0);
}
