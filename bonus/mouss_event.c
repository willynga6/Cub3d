/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouss_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:42:39 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 17:53:51 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

/*	=======================================================	*/

static void	shooting_case_update_game(t_game *game)
{
	game->gun.is_shooting = true;
	game->gun.is_reloading = false;
	game->gun.current_frame = 0;
	game->gun.animation_timer = 0;
	game->gun.ammunition--;
}

/*	=======================================================	*/

static void	reloading_case_update_game(t_game *game)
{
	game->gun.is_reloading = true;
	game->gun.is_shooting = false;
	game->gun.current_frame = 0;
	game->gun.animation_timer = 0;
}

int	mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
	{
		if (game->gun.ammunition > 0 && !game->gun.is_shooting
			&& !game->gun.is_reloading)
			shooting_case_update_game(game);
		else if (game->gun.ammunition <= 0 && !game->gun.is_reloading)
			reloading_case_update_game(game);
	}
	if (button == RIGHT_CLICK)
	{
		if (game->gun.ammunition < 10 && !game->gun.is_reloading
			&& !game->gun.is_shooting)
			reloading_case_update_game(game);
	}
	return (0);
}

/*	=======================================================	*/

void	draw_gun(t_game *game)
{
	t_texture	*tex;
	int			y;
	int			x;
	int			color;

	if (game->gun.is_reloading)
		tex = &game->gun.frame_reload[game->gun.current_frame];
	else if (game->gun.is_shooting)
		tex = &game->gun.frame_shoot[game->gun.current_frame];
	else
		tex = &game->gun.frame_idle[game->gun.current_frame];
	game->gun.gun_x = WIN_WIDTH / 2 - tex->width / 2;
	game->gun.gun_y = WIN_HEIGHT - tex->height;
	y = -1;
	while (++y < tex->height)
	{
		x = -1;
		while (++x < tex->width)
		{
			color = get_texture_pixel(tex, x, y);
			if (color != (int)(0xFF000000))
				put_pixel(game, game->gun.gun_x
					+ x, game->gun.gun_y + y, color);
		}
	}
}
