/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:17:41 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 12:29:07 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_texture	*select_texture(t_game *game, int side, double ray_dir_x,
		double ray_dir_y)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (&game->ea);
		return (&game->we);
	}
	else
	{
		if (ray_dir_y > 0)
			return (&game->so);
		return (&game->no);
	}
}

static int	is_transparent(int color)
{
	return (color == 0 || color == (int)0xFF000000);
}

void	draw_texture_line(t_game *game, t_texture *tex, t_draw_line *d)
{
	int	y;
	int	tex_y;
	int	color;

	y = d->draw_start;
	while (y < d->draw_end)
	{
		tex_y = (int)d->tex_pos;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		d->tex_pos += d->step;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		color = get_texture_pixel(tex, d->tex_x, tex_y);
		put_pixel(game, d->x, y, color);
		y++;
	}
}

void	draw_texture_line_trans(t_game *game, t_texture *tex, t_draw_line *d)
{
	int	y;
	int	tex_y;
	int	color;

	y = d->draw_start;
	while (y < d->draw_end)
	{
		tex_y = (int)d->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		d->tex_pos += d->step;
		color = get_texture_pixel(tex, d->tex_x, tex_y);
		if (!is_transparent(color))
			put_pixel(game, d->x, y, color);
		y++;
	}
}
