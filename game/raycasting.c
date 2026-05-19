/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:51:17 by otidahoh          #+#    #+#             */
/*   Updated: 2026/05/14 17:19:32 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_vertical_line(t_game *game, int x, int start, int end,
		int color)
{
	while (start < end)
	{
		put_pixel(game, x, start, color);
		start++;
	}
}

void	cast_ray(t_game *game)
{
	t_player	*p;
	int			color;
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

	p = &game->parsing.player;
	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
		ray_dir_x = p->dir_x + p->plane_x * camera_x;
		ray_dir_y = p->dir_y + p->plane_y * camera_x;
		map_x = (int)p->pos_x;
		map_y = (int)p->pos_y;
		delta_dist_x = fabs(1 / ray_dir_x);
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
			if (game->parsing.final_maps.map[map_y][map_x] == '1')
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
		if (side == 1)
			color = 0xAAAAAA;
		else
			color = 0xFFFFFF;
		draw_vertical_line(game, x, draw_start, draw_end, color);
		x++;
	}
}
