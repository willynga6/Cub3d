/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:50:55 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 16:18:41 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <sys/time.h>

/*  ======================================================  */

void	game_loop_init(t_game *game)
{
	game->game_loop.current = 0;
	game->game_loop.dt = 0;
	game->game_loop.move_speed = 0;
	game->game_loop.rot_speed = 0;
	game->game_loop.new_x = 0;
	game->game_loop.new_y = 0;
	game->game_loop.player = &game->parsing.player;
}

/*  ======================================================  */

int	is_wall(t_parsing *p, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (my < 0 || my >= p->final_maps.nb_lines)
		return (1);
	if (mx < 0 || mx >= (int)ft_strlen(p->final_maps.map[my]))
		return (1);
	if (p->final_maps.map[my][mx] == '1')
		return (1);
	if (p->final_maps.map[my][mx] == 'D'
		&& p->final_maps.door_open[my][mx] == 0)
		return (1);
	return (0);
}
