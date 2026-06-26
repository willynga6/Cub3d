/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:35:03 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/24 11:35:03 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"
#define GUN_SCALE 11
#define GUN_RIGHT_MARGIN 160
#define GUN_BOTTOM_OFFSET 20

/*	===================================================================	*/

static bool	load_gun_frame_idle(t_game *game)
{
	if (!load_texture(game, &game->gun.frame_idle[0], "textures/gunidle_0.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_idle[1], "textures/gun_idle1.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_idle[2], "textures/gun_idle2.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_idle[3], "textures/gun_idle1.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_idle[4], "textures/gunidle_0.xpm"))
		return (false);
	return (true);
}

/*	===================================================================	*/

static bool	load_gun_frame_shoot(t_game *game)
{
	if (!load_texture(game, &game->gun.frame_shoot[0],
			"textures/gunshoot_0.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_shoot[1],
			"textures/gunshoot_1.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_shoot[2],
			"textures/gunshoot_2.xpm"))
		return (false);
	return (true);
}

/*	===================================================================	*/

static bool	load_gun_frame_reload(t_game *game)
{
	if (!load_texture(game, &game->gun.frame_reload[0],
			"textures/gun_idle1.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_reload[1], "textures/reload1.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_reload[2], "textures/reload2.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_reload[3], "textures/reload3.xpm"))
		return (false);
	if (!load_texture(game, &game->gun.frame_reload[4],
			"textures/gunidle_0.xpm"))
		return (false);
	return (true);
}

/*	===================================================================	*/

int	load_gun(t_game *game)
{
	if (!load_gun_frame_idle(game))
		return (0);
	if (!load_gun_frame_shoot(game))
		return (0);
	if (!load_gun_frame_reload(game))
		return (0);
	return (1);
}
