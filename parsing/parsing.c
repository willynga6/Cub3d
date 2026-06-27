/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:51:07 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 17:55:00 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	parsing(t_game *game, char **av, int ac, t_malloc **lst_malloc)
{
	if (ac != 2)
	{
		printf("Program need two arguments to run: ./cub3D path/of/map.cub\n");
		return (false);
	}
	if (!check_extension(av[1]))
		return (false);
	if (!init_lst_malloc(lst_malloc))
		return (false);
	if (!init_parsing(av, ac, &game->parsing, lst_malloc))
		return (clean_and_close(lst_malloc, game->parsing.fd_map), false);
	if (!check_the_mapfile_format(&game->parsing))
		return (clean_and_close(lst_malloc, game->parsing.fd_map), false);
	if (!flood_fill(&game->parsing, lst_malloc))
		return (clean_and_close(lst_malloc, game->parsing.fd_map), false);
	extract_player(&game->parsing);
	return (true);
}
