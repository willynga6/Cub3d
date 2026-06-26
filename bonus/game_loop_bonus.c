/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:19:31 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 17:54:48 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

/*  ======================================================  */

static void	move_up_case(t_game *game)
{
	t_game_loop	*loop;
	t_player	*p;

	loop = &game->game_loop;
	p = &game->parsing.player;
	loop->new_x = p->pos_x + p->dir_x * loop->move_speed;
	if (!is_wall(&game->parsing, loop->new_x, p->pos_y))
		p->pos_x = loop->new_x;
	loop->new_y = p->pos_y + p->dir_y * loop->move_speed;
	if (!is_wall(&game->parsing, p->pos_x, loop->new_y))
		p->pos_y = loop->new_y;
}

/*  ======================================================  */

static void	move_down_case(t_game *game)
{
	t_game_loop	*loop;
	t_player	*p;

	loop = &game->game_loop;
	p = &game->parsing.player;
	loop->new_x = p->pos_x - p->dir_x * loop->move_speed;
	if (!is_wall(&game->parsing, loop->new_x, p->pos_y))
		p->pos_x = loop->new_x;
	loop->new_y = p->pos_y - p->dir_y * loop->move_speed;
	if (!is_wall(&game->parsing, p->pos_x, loop->new_y))
		p->pos_y = loop->new_y;
}

/*  ======================================================  */

static void	move_left_case(t_game *game)
{
	t_game_loop	*loop;
	t_player	*p;

	loop = &game->game_loop;
	p = &game->parsing.player;
	loop->new_x = p->pos_x - p->plane_x * loop->move_speed;
	if (!is_wall(&game->parsing, loop->new_x, p->pos_y))
		p->pos_x = loop->new_x;
	loop->new_y = p->pos_y - p->plane_y * loop->move_speed;
	if (!is_wall(&game->parsing, p->pos_x, loop->new_y))
		p->pos_y = loop->new_y;
}

/*  ======================================================  */

static void	move_right_case(t_game *game)
{
	t_game_loop	*loop;
	t_player	*p;

	loop = &game->game_loop;
	p = &game->parsing.player;
	loop->new_x = p->pos_x + p->plane_x * loop->move_speed;
	if (!is_wall(&game->parsing, loop->new_x, p->pos_y))
		p->pos_x = loop->new_x;
	loop->new_y = p->pos_y + p->plane_y * loop->move_speed;
	if (!is_wall(&game->parsing, p->pos_x, loop->new_y))
		p->pos_y = loop->new_y;
}

int	game_loop_bonus(t_game *game)
{
	double		dt;
	t_player	*p;

	game->game_loop.current = get_time();
	dt = game->game_loop.current - game->last_time;
	game->last_time = game->game_loop.current;
	game->game_loop.move_speed = 3.0 * dt;
	game->game_loop.rot_speed = 2.0 * dt;
	p = &game->parsing.player;
	if (p->move_up)
		move_up_case(game);
	if (p->move_down)
		move_down_case(game);
	if (p->move_left)
		move_left_case(game);
	if (p->move_right)
		move_right_case(game);
	if (p->rotate_left)
		rotate_p(p, -game->game_loop.rot_speed);
	if (p->rotate_right)
		rotate_p(p, game->game_loop.rot_speed);
	update_gun(game, dt);
	render_frame_bonus(game);
	return (0);
}
