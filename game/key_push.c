/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:39:13 by otidahoh          #+#    #+#             */
/*   Updated: 2026/05/15 08:55:37 by otidahoh         ###   ########.fr       */
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
	if (keycode == 119)
		game->parsing.player.move_up = 1;
	if (keycode == 115)
		game->parsing.player.move_down = 1;
	if (keycode == 97)
		game->parsing.player.move_left = 1;
	if (keycode == 100)
		game->parsing.player.move_right = 1;
	if (keycode == 65361)
		game->parsing.player.rotate_left = 1;
	if (keycode == 65363)
		game->parsing.player.rotate_right = 1;
	printf("PRESS: %d\n", keycode);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 119)
		game->parsing.player.move_up = 0;
	if (keycode == 115)
		game->parsing.player.move_down = 0;
	if (keycode == 97)
		game->parsing.player.move_left = 0;
	if (keycode == 100)
		game->parsing.player.move_right = 0;
	if (keycode == 65361)
		game->parsing.player.rotate_left = 0;
	if (keycode == 65363)
		game->parsing.player.rotate_right = 0;
	printf("RELEASE: %d\n", keycode);
	return (0);
}

double	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

static int	is_wall(t_parsing *p, double x, double y)
{
	int mx = (int)x;
	int my = (int)y;

	if (my < 0 || my >= p->final_maps.nb_lines)
		return (1);
	if (mx < 0 || mx >= (int)ft_strlen(p->final_maps.map[my]))
		return (1);
	if (p->final_maps.map[my][mx] == '1')
		return (1);
	return (0);
}

int	game_loop(t_game *game)
{
	double current = get_time();
	double dt = current - game->last_time;
	game->last_time = current;

	double move_speed = 3.0 * dt;
	double rot_speed = 2.0 * dt;

	t_player *p = &game->parsing.player;

	double new_x, new_y;

	if (p->move_up)
	{
		new_x = p->pos_x + p->dir_x * move_speed;
		new_y = p->pos_y + p->dir_y * move_speed;

		if (!is_wall(&game->parsing, new_x, new_y))
		{
			p->pos_x = new_x;
			p->pos_y = new_y;
		}
	}

	if (p->move_down)
	{
		new_x = p->pos_x - p->dir_x * move_speed;
		new_y = p->pos_y - p->dir_y * move_speed;

		if (!is_wall(&game->parsing, new_x, new_y))
		{
			p->pos_x = new_x;
			p->pos_y = new_y;
		}
	}

	if (p->move_left)
	{
		new_x = p->pos_x + p->dir_y * move_speed;
		new_y = p->pos_y - p->dir_x * move_speed;

		if (!is_wall(&game->parsing, new_x, new_y))
		{
			p->pos_x = new_x;
			p->pos_y = new_y;
		}
	}

	if (p->move_right)
	{
		new_x = p->pos_x - p->dir_y * move_speed;
		new_y = p->pos_y + p->dir_x * move_speed;

		if (!is_wall(&game->parsing, new_x, new_y))
		{
			p->pos_x = new_x;
			p->pos_y = new_y;
		}
	}

	if (p->rotate_left)
		rotate_p(p, -rot_speed);
	if (p->rotate_right)
		rotate_p(p, rot_speed);

	render_frame(game);
	return (0);
}
