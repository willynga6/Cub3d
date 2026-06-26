/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:20:47 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 20:28:46 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "structure.h"

// Initialiser le rayon
void	init_ray(t_game *game)
{
	t_raycasting	*r;
	t_player		*p;

	r = &game->ray;
	p = &game->parsing.player;
	r->camera_x = 2.0 * r->x / (double)WIN_WIDTH - 1.0;
	r->ray_dir_x = p->dir_x + p->plane_x * r->camera_x;
	r->ray_dir_y = p->dir_y + p->plane_y * r->camera_x;
	r->map_x = (int)p->pos_x;
	r->map_y = (int)p->pos_y;
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
	r->hit = 0;
	r->door_found = 0;
}

/*  ==============================================================  */
// Initialiser les steps DDA
void	init_dda(t_game *game)
{
	t_raycasting	*r;
	t_player		*p;

	r = &game->ray;
	p = &game->parsing.player;
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (p->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - p->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (p->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - p->pos_y) * r->delta_dist_y;
	}
}

/*  ==============================================================  */

// Avancer dans la MAP
void	move_ray_one_step(t_raycasting *r)
{
	if (r->side_dist_x < r->side_dist_y)
	{
		r->side_dist_x += r->delta_dist_x;
		r->map_x += r->step_x;
		r->side = 0;
	}
	else
	{
		r->side_dist_y += r->delta_dist_y;
		r->map_y += r->step_y;
		r->side = 1;
	}
}

/*  ==============================================================  */

// Gerer les murs et les portes
void	check_ray_tile(t_game *game)
{
	t_raycasting	*r;

	r = &game->ray;
	r->tile = game->parsing.final_maps.map[r->map_y][r->map_x];
	if (r->tile == '1' || r->tile == ' ')
		r->hit = 1;
	if (r->tile == 'D')
	{
		if (game->parsing.final_maps.door_open[r->map_y][r->map_x] == 0)
			r->hit = 1;
		else if (r->door_found == 0)
		{
			r->door_found = 1;
			r->door_x = r->map_x;
			r->door_y = r->map_y;
			r->door_side = r->side;
		}
	}
}

