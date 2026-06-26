/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                             :+:      :+:    :+:   */
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
#include <string.h>

static void	reload_gun(t_game *game)
{
	t_gun	*gun;

	gun = &game->gun;
	if (!gun->is_reloading)
		return ;
	if (gun->animation_timer >= 0.35)
	{
		gun->current_frame++;
		gun->animation_timer = 0;
		if (gun->current_frame >= 5)
		{
			gun->ammunition = 10;
			gun->is_reloading = false;
			gun->current_frame = 0;
			gun->animation_timer = 0;
		}
	}
}

void	init_gun(t_game *game)
{
	t_gun	*gun;

	gun = &game->gun;
	memset(gun, 0, sizeof(t_gun));
	gun->ammunition = 10;
}

static void	shooting_case(t_game *game)
{
	t_gun	*gun;

	gun = &game->gun;
	if (gun->ammunition <= 0)
	{
		gun->is_shooting = false;
		return ;
	}
	if (gun->animation_timer >= 0.08)
	{
		gun->current_frame++;
		gun->animation_timer = 0;
		if (gun->current_frame >= 3)
		{
			gun->current_frame = 0;
			gun->is_shooting = false;
		}
	}
}

static void	update_animation_gun(t_game *game)
{
	t_gun	*gun;

	gun = &game->gun;
	if (gun->animation_timer >= 0.12)
	{
		gun->current_frame++;
		gun->animation_timer = 0;
		if (gun->current_frame >= 5)
			gun->current_frame = 0;
	}
}

void	update_gun(t_game *game, double dt)
{
	t_gun	*gun;

	gun = &game->gun;
	gun->animation_timer += dt;
	if (gun->is_shooting)
		shooting_case(game);
	else if (gun->is_reloading)
		reload_gun(game);
	else
		update_animation_gun(game);
}
