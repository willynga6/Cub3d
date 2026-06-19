/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:34:10 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/19 14:37:34 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	parsing(t_game *game, char **av, int ac, t_malloc **lst_malloc)
{
	if (!check_extension(av[1]))
		return (false);
	if (!init_lst_malloc(lst_malloc))
		return (false);
	if (!init_parsing(av, ac, &game->parsing, lst_malloc))
		return (free_lst_malloc(lst_malloc), false);
	if (!check_the_mapfile_format(&game->parsing))
		return (free_lst_malloc(lst_malloc), false);
	if (!flood_fill(&game->parsing, lst_malloc))
		return (free_lst_malloc(lst_malloc), false);
	return (true);
}
