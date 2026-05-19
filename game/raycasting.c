/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:51:17 by otidahoh          #+#    #+#             */
/*   Updated: 2026/05/19 17:50:48 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_texture	*select_texture(t_game *game, int side, double ray_dir_x,
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

void	draw_texture_line(
	t_game *game,
	t_texture *tex,
	int x,
	int draw_start,
	int draw_end,
	int tex_x,
	double step,
	double tex_pos)
{
	int	y;
	int	tex_y;
	int	color;

	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		tex_pos += step;

		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;

		color = get_texture_pixel(tex, tex_x, tex_y);
		put_pixel(game, x, y, color);
		y++;
	}
}

/*static void	draw_vertical_line(t_game *game, int x, int start, int end,
		int color)
{
	while (start < end)
	{
		put_pixel(game, x, start, color);
		start++;
	}
}*/

void	cast_ray(t_game *game)
{
	t_player	*p;
	//int			color;
	t_texture *tex;
	double wall_x;
	int tex_x;
	double step;
	double tex_pos;
	int			x;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	char tile;

	p = &game->parsing.player;
	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
		ray_dir_x = p->dir_x + p->plane_x * camera_x;
		ray_dir_y = p->dir_y + p->plane_y * camera_x;
		map_x = (int)p->pos_x;
		map_y = (int)p->pos_y;
		if (ray_dir_x == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / ray_dir_x);

		if (ray_dir_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / ray_dir_y);
		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (p->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - p->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (p->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - p->pos_y) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (map_y < 0 || map_y >= game->parsing.final_maps.nb_lines
				|| map_x < 0
				|| map_x >= game->parsing.final_maps.max_line_length)
				break ;
			tile = game->parsing.final_maps.map[map_y][map_x];
			if (tile == '1' || tile == ' ')
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - p->pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - p->pos_y + (1 - step_y) / 2) / ray_dir_y;
		line_height = (int)(WIN_HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WIN_HEIGHT / 2;
		if (draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;
		tex = select_texture(game, side, ray_dir_x, ray_dir_y);

		if (side == 0)
			wall_x = p->pos_y + perp_wall_dist * ray_dir_y;
		else
			wall_x = p->pos_x + perp_wall_dist * ray_dir_x;

		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * tex->width);

		if (side == 0 && ray_dir_x > 0)
			tex_x = tex->width - tex_x - 1;
		if (side == 1 && ray_dir_y < 0)
			tex_x = tex->width - tex_x - 1;
		if (tex_x < 0)
			tex_x = 0;
		if (tex_x >= tex->width)
			tex_x = tex->width - 1;
		step = (double)tex->height / (double)line_height;
		tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;

		draw_texture_line(game, tex, x, draw_start, draw_end, tex_x, step, tex_pos);
		x++;
	}
}
