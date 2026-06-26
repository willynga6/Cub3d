/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:14:45 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 20:53:00 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_frame_bonus(t_game *game)
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
	draw_minimap(game);
	draw_minimap_player(game);
	draw_minimap_dir(game);
	draw_cross_s(game);
	render_gun(game);
	display_image(game);
	return (0);
}
