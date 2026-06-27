/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:26:52 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 12:40:58 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "structure.h"

// Desinner le mur ou la porte fermee

t_texture	*get_hit_texture(t_game *game)
{
	t_raycasting	*r;

	r = &game->ray;
	r->tile = game->parsing.final_maps.map[r->map_y][r->map_x];
	if (r->tile == 'D')
	{
		if (game->parsing.final_maps.door_open[r->map_y][r->map_x] == 1)
			return (&game->door.door_frame[0]);
		return (&game->door.door_frame[1]);
	}
	return (select_texture(game, r->side, r->ray_dir_x, r->ray_dir_y));
}

void	draw_wall_hit(t_game *game)
{
	t_raycasting	*r;
	t_texture		*tex;
	t_draw_line		d;

	r = &game->ray;
	compute_wall_projection(game);
	tex = get_hit_texture(game);
	compute_tex_x(game, tex);
	r->step = (double)tex->height / (double)r->line_height;
	r->tex_pos = (r->draw_start - WIN_HEIGHT / 2
			+ r->line_height / 2) * r->step;
	d.x = r->x;
	d.draw_start = r->draw_start;
	d.draw_end = r->draw_end;
	d.tex_x = r->tex_x;
	d.step = r->step;
	d.tex_pos = r->tex_pos;
	draw_texture_line(game, tex, &d);
}

/*  ============================================================    */

// Dessiner la porte ouverte traversee

void	compute_open_door_projection(t_game *game)
{
	t_raycasting	*r;
	t_player		*p;

	r = &game->ray;
	p = &game->parsing.player;
	if (r->door_side == 0)
		r->door_dist = (r->door_x - p->pos_x
				+ (1 - r->step_x) / 2) / r->ray_dir_x;
	else
		r->door_dist = (r->door_y - p->pos_y
				+ (1 - r->step_y) / 2) / r->ray_dir_y;
	r->line_height = (int)(WIN_HEIGHT / r->door_dist);
	r->draw_start = -r->line_height / 2 + WIN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + WIN_HEIGHT / 2;
	if (r->draw_end >= WIN_HEIGHT)
		r->draw_end = WIN_HEIGHT - 1;
}

void	compute_open_door_tex_x(t_game *game, t_texture *tex)
{
	t_raycasting	*r;
	t_player		*p;

	r = &game->ray;
	p = &game->parsing.player;
	if (r->door_side == 0)
		r->wall_x = p->pos_y + r->door_dist * r->ray_dir_y;
	else
		r->wall_x = p->pos_x + r->door_dist * r->ray_dir_x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * tex->width);
	if (r->door_side == 0 && r->ray_dir_x > 0)
		r->tex_x = tex->width - r->tex_x - 1;
	if (r->door_side == 1 && r->ray_dir_y < 0)
		r->tex_x = tex->width - r->tex_x - 1;
}

void	draw_open_door_if_needed(t_game *game)
{
	t_raycasting	*r;
	t_texture		*tex;
	t_draw_line		d;

	r = &game->ray;
	if (r->door_found == 0)
		return ;
	tex = &game->door.door_frame[0];
	compute_open_door_projection(game);
	compute_open_door_tex_x(game, tex);
	r->step = (double)tex->height / (double)r->line_height;
	r->tex_pos = (r->draw_start - WIN_HEIGHT / 2
			+ r->line_height / 2) * r->step;
	d.x = r->x;
	d.draw_start = r->draw_start;
	d.draw_end = r->draw_end;
	d.tex_x = r->tex_x;
	d.step = r->step;
	d.tex_pos = r->tex_pos;
	draw_texture_line_trans(game, tex, &d);
}
