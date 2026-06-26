/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:35:03 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/24 11:35:03 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"
#define GUN_SCALE 11
#define GUN_RIGHT_MARGIN 160
#define GUN_BOTTOM_OFFSET 20

/*	===================================================================	*/

static int	is_transparent(int color)
{
	return (color == (int)0xFF000000 || color == 0x00000000);
}

/*	===================================================================	*/

static void	put_scaled_pixel(t_game *game, int sx, int sy, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < GUN_SCALE)
	{
		x = 0;
		while (x < GUN_SCALE)
		{
			put_pixel(game, sx + x, sy + y, color);
			x++;
		}
		y++;
	}
}

/*	===================================================================	*/

static void	draw_texture(t_game *game, t_texture *tex, int start_x, int start_y)
{
	int	x;
	int	y;
	int	color;

	if (!tex || !tex->addr || tex->width <= 0 || tex->height <= 0)
		return ;
	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			color = get_texture_pixel(tex, x, y);
			if (!is_transparent(color))
				put_scaled_pixel(game, start_x + x * GUN_SCALE,
					start_y + y * GUN_SCALE, color);
			x++;
		}
		y++;
	}
}

/*	===================================================================	*/

static t_texture	*get_gun_texture(t_game *game)
{
	if (game->gun.is_reloading)
	{
		if (game->gun.current_frame < 0 || game->gun.current_frame >= 5)
			game->gun.current_frame = 0;
		return (&game->gun.frame_reload[game->gun.current_frame]);
	}
	if (game->gun.is_shooting)
	{
		if (game->gun.current_frame < 0 || game->gun.current_frame >= 3)
			game->gun.current_frame = 0;
		return (&game->gun.frame_shoot[game->gun.current_frame]);
	}
	if (game->gun.current_frame < 0 || game->gun.current_frame >= 5)
		game->gun.current_frame = 0;
	return (&game->gun.frame_idle[game->gun.current_frame]);
}

/*	===================================================================	*/

void	render_gun(t_game *game)
{
	t_texture	*tex;
	int			x;
	int			y;

	tex = get_gun_texture(game);
	if (!tex || !tex->addr)
		return ;
	x = WIN_WIDTH - (tex->width * GUN_SCALE) - GUN_RIGHT_MARGIN;
	y = WIN_HEIGHT - (tex->height * GUN_SCALE) + GUN_BOTTOM_OFFSET;
	draw_texture(game, tex, x, y);
}
