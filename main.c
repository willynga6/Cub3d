/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:35:49 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/20 15:20:17 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "structure.h"

/*int	main(int ac, char **av)
{
	t_parsing	parsing;
	t_malloc	*lst_malloc;
	t_game		game;
	t_malloc	*lst_malloc;

	lst_malloc = NULL;
	if (!init_lst_malloc(&lst_malloc))
		return (1);
	if (!init_parsing (av, ac, &parsing, &lst_malloc))
		return (free_lst_malloc(&lst_malloc), 1);
	check_the_mapfile_format(&parsing);
	flood_fill(&parsing, &lst_malloc);
	clean_and_close(&lst_malloc, parsing.fd_map);
	return (0);
}*/

int	main(int ac, char **av)
{
    t_game      game;
    t_malloc    *lst_malloc;

	lst_malloc = NULL;
	if (!init_lst_malloc(&lst_malloc))
		return (1);
	if (!init_parsing(av, ac, &game.parsing, &lst_malloc))
		return (free_lst_malloc(&lst_malloc), 1);
	if (!check_the_mapfile_format(&game.parsing))
		return (free_lst_malloc(&lst_malloc), 1);
	if (!flood_fill(&game.parsing, &lst_malloc))
		return (free_lst_malloc(&lst_malloc), 1);
	extract_player(&game.parsing);
	if (!init_mlx(&game))
		return (free_lst_malloc(&lst_malloc), 1);
	game.prev_ms_x = WIN_WIDTH / 2;
	mlx_mouse_move(game.mlx.mlx,
		game.mlx.win,
		WIN_WIDTH / 2,
		WIN_HEIGHT / 2);
	mlx_hook(game.mlx.win, 6, 1L << 6, mouse_move, &game);
	if (!load_all_textures(&game))
		return (1);
	init_image(&game);
	mlx_hook(game.mlx.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx.mlx, game_loop, &game);
	mlx_loop(game.mlx.mlx);
	clean_and_close(&lst_malloc, game.parsing.fd_map);
	return (0);
}

