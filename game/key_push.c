/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:19:37 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 14:20:16 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <sys/time.h>

int	close_window(t_game *game)
{
	(void)game;
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 101)
		toggle_door(game);
	if (keycode == 114 && game->gun.ammunition < 10
		&& !game->gun.is_reloading && !game->gun.is_shooting)
	{
		game->gun.is_reloading = true;
		game->gun.current_frame = 0;
		game->gun.animation_timer = 0;
	}
	if (keycode == 119 || keycode == 65362)
		game->parsing.player.move_up = 1;
	if (keycode == 115 || keycode == 65364)
		game->parsing.player.move_down = 1;
	if (keycode == 97)
		game->parsing.player.move_left = 1;
	if (keycode == 100)
		game->parsing.player.move_right = 1;
	if (keycode == 65361)
		game->parsing.player.rotate_left = 1;
	if (keycode == 65363)
		game->parsing.player.rotate_right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 119 || keycode == 65362)
		game->parsing.player.move_up = 0;
	if (keycode == 115 || keycode == 65364)
		game->parsing.player.move_down = 0;
	if (keycode == 97)
		game->parsing.player.move_left = 0;
	if (keycode == 100)
		game->parsing.player.move_right = 0;
	if (keycode == 65361)
		game->parsing.player.rotate_left = 0;
	if (keycode == 65363)
		game->parsing.player.rotate_right = 0;
	return (0);
}

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

void	draw_cross_s(t_game *game)
{
	int	cy;
	int	cx;
	int	i;
	int	t;

	cx = WIN_WIDTH / 2;
	cy = WIN_HEIGHT / 2;
	i = -15;
	while (i <= 15)
	{
		t = -2;
		put_pixel(game, cx + i, cy, 0x87CEEB);
		put_pixel(game, cx, cy + i, 0x87CEEB);
		while (t <= 2)
		{
			put_pixel(game, cx + i, cy + t, 0x87CEEB);
			put_pixel(game, cx + t, cy + i, 0x87CEEB);
			t++;
		}
		i++;
	}
}
