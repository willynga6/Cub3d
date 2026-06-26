/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:57:11 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 16:55:05 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	=====================================================================	*/

void	draw_square(t_game *game, int map_x, int map_y, int color)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = map_x * TILE_SIZE;
	start_y = map_y * TILE_SIZE;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			put_pixel(game, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

/*	=====================================================================	*/

void	draw_ceiling_and_floor(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel(game, x, y, 0x3B2F2F);
			else
				put_pixel(game, x, y, 0x5C4033);
			x++;
		}
		y++;
	}
}

/*	=====================================================================	*/

int	render_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(game, x, y, 0x000000);
			x++;
		}
		y++;
	}
	draw_ceiling_and_floor(game);
	cast_ray(game);
	draw_cross_s(game);
	display_image(game);
	return (0);
}
