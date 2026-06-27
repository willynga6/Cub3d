/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:18:33 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 15:06:19 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_mm_tile(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MM_SCALE)
	{
		j = 0;
		while (j < MM_SCALE)
		{
			put_pixel(game, MM_OFFSET_X + x * MM_SCALE + i, MM_OFFSET_Y + y
				* MM_SCALE + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (game->parsing.final_maps.map[y])
	{
		x = 0;
		while (game->parsing.final_maps.map[y][x])
		{
			tile = game->parsing.final_maps.map[y][x];
			if (tile == '1')
				draw_mm_tile(game, x, y, 0x222222);
			else
				draw_mm_tile(game, x, y, 0xAAAAAA);
			x++;
		}
		y++;
	}
}

void	draw_minimap_player(t_game *game)
{
	int	px;
	int	py;
	int	i;
	int	j;

	px = game->parsing.player.pos_x * MM_SCALE;
	py = game->parsing.player.pos_y * MM_SCALE;
	i = -3;
	while (i <= 3)
	{
		j = -3;
		while (j <= 3)
		{
			put_pixel(game, MM_OFFSET_X + px + i, MM_OFFSET_Y + py + j,
				0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_minimap_dir(t_game *game)
{
	int	i;
	int	px;
	int	py;

	i = 0;
	px = game->parsing.player.pos_x * MM_SCALE;
	py = game->parsing.player.pos_y * MM_SCALE;
	while (i < 10)
	{
		put_pixel(game, MM_OFFSET_X + px + game->parsing.player.dir_x * i,
			MM_OFFSET_Y + py + game->parsing.player.dir_y * i, 0x00FF00);
		i++;
	}
}
