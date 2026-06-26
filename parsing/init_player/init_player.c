/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:51:33 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:14:07 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "structure.h"

/*	==========================================================	*/

static void	init_player_int_values(t_player *player)
{
	player->move_up = 0;
	player->move_down = 0;
	player->move_left = 0;
	player->move_right = 0;
	player->rotate_left = 0;
	player->rotate_right = 0;
}

/*	==========================================================	*/

static void	init_player_double_values(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
}

/*	==========================================================	*/

void	init_player_int_double_value(t_player *player)
{
	if (!player)
		return ;
	init_player_int_values(player);
	init_player_double_values(player);
	player->map_x = 0;
	player->map_y = 0;
	player->flood_f_map = NULL;
}

/*	==========================================================	*/

static void	update_player_pos(t_player *player, int x, int y)
{
	if (!player)
		return ;
	player->map_x = x;
	player->map_y = y;
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
}

void	extract_player(t_parsing *p)
{
	int	x;
	int	y;

	if (!p || !p->final_maps.map)
		return ;
	init_player_int_double_value(&p->player);
	y = 0;
	while (p->final_maps.map[y])
	{
		x = 0;
		while (p->final_maps.map[y][x])
		{
			if (is_player_char(p->final_maps.map[y][x]))
			{
				init_player_dir(&p->player, p->final_maps.map[y][x]);
				update_player_pos(&p->player, x, y);
				p->final_maps.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
