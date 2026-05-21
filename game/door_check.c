/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:53:20 by otidahoh          #+#    #+#             */
/*   Updated: 2026/05/21 12:48:03 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	init_doors(t_parsing *parsing)
{
	int	y;
	int	x;

	if (!parsing || !parsing->final_maps.map)
		return (false);
	parsing->final_maps.door_open = malloc_remix(parsing->lst_malloc,
			sizeof(int *) * parsing->nb_lines);
	if (!parsing->final_maps.door_open)
		return (false);
	y = 0;
	while (y < parsing->nb_lines)
	{
		parsing->final_maps.door_open[y] = malloc_remix(parsing->lst_malloc,
				sizeof(int) * parsing->final_maps.max_line_length);
		if (!parsing->final_maps.door_open[y])
			return (false);
		x = 0;
		while (x < parsing->final_maps.max_line_length)
		{
			parsing->final_maps.door_open[y][x] = 1;
			if (parsing->final_maps.map[y][x] == 'D')
				parsing->final_maps.door_open[y][x] = 0;
			x++;
		}
		y++;
	}
	return (true);
}

void	toggle_door(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->parsing.player.pos_x + game->parsing.player.dir_x);
	y = (int)(game->parsing.player.pos_y + game->parsing.player.dir_y);
	if (y < 0 || y >= game->parsing.final_maps.nb_lines)
		return ;
	if (x < 0 || x >= game->parsing.final_maps.max_line_length)
		return ;
	if (game->parsing.final_maps.map[y][x] == 'D')
	{
		if (game->parsing.final_maps.door_open[y][x] == 0)
			game->parsing.final_maps.door_open[y][x] = 1;
		else
			game->parsing.final_maps.door_open[y][x] = 0;
	}
}
