/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:35:13 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 16:21:11 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <string.h>

/*	================================================================	*/

static bool	load_wall_texture(t_game *game)
{
	if (!game)
		return (false);
	if (!load_texture(game, &game->no, game->parsing.no_texture))
		return (false);
	if (!load_texture(game, &game->so, game->parsing.so_texture))
		return (false);
	if (!load_texture(game, &game->we, game->parsing.we_texture))
		return (false);
	if (!load_texture(game, &game->ea, game->parsing.ea_texture))
		return (false);
	return (true);
}

/*	================================================================	*/

static bool	load_door_texture(t_game *game)
{
	if (!game)
		return (false);
	if (!load_texture(game, &game->door.door_frame[0],
			"textures/open_door.xpm"))
		return (false);
	if (!load_texture(game, &game->door.door_frame[1], "textures/door.xpm"))
		return (false);
	return (true);
}

/*	================================================================	*/

int	load_all_textures(t_game *game)
{
	if (!load_wall_texture(game))
		return (0);
	if (!load_door_texture(game))
		return (0);
	if (!load_gun(game))
		return (0);
	return (1);
}
