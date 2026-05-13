/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:39:13 by otidahoh          #+#    #+#             */
/*   Updated: 2026/05/13 13:29:39 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	return (0);
}

int	game_loop(t_game *game)
{
	double move_speed = 0.1;
	double rot_speed = 0.05;
	double new_x, new_y;

	t_player *p = &game->parsing.player;

	if (p->move_up)
	{
		new_x = p->pos_x + p->dir_x * move_speed;
		new_y = p->pos_y + p->dir_y * move_speed;
		if (game->parsing.final_maps.map[(int)new_y][(int)new_x] != '1')
		{
			p->pos_x = new_x;
			p->pos_y = new_y;
		}
	}

	if (p->move_down)
	{
		new_x = p->pos_x - p->dir_x * move_speed;
		new_y = p->pos_y - p->dir_y * move_speed;
		if (game->parsing.final_maps.map[(int)new_y][(int)new_x] != '1')
		{
			p->pos_x = new_x;
			p->pos_y = new_y;
		}
	}

	if (p->move_left)
	{
		new_x = p->pos_x - p->dir_y * move_speed;
		new_y = p->pos_y + p->dir_x * move_speed;
		if (game->parsing.final_maps.map[(int)new_y][(int)new_x] != '1')
		{
			p->pos_x = new_x;
			p->pos_y = new_y;
		}
	}

	if (p->move_right)
	{
		new_x = p->pos_x + p->dir_y * move_speed;
		new_y = p->pos_y - p->dir_x * move_speed;
		if (game->parsing.final_maps.map[(int)new_y][(int)new_x] != '1')
		{
			p->pos_x = new_x;
			p->pos_y = new_y;
		}
	}

	if (p->rotate_left)
		rotate_p(p, -rot_speed);
	if (p->rotate_right)
		rotate_p(p, rot_speed);

	p->map_x = (int)p->pos_x;
	p->map_y = (int)p->pos_y;

	render_frame(game);
	return (0);
}
