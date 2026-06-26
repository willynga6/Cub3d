/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:24:33 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 20:28:37 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "structure.h"

// Boucle DDA complete

int	is_ray_outside_map(t_game *game)
{
	t_raycasting	*r;

	r = &game->ray;
	if (r->map_y < 0 || r->map_y >= game->parsing.final_maps.nb_lines)
		return (1);
	if (r->map_x < 0
		|| r->map_x >= game->parsing.final_maps.max_line_length)
		return (1);
	return (0);
}

void	perform_dda(t_game *game)
{
	t_raycasting	*r;

	r = &game->ray;
	while (r->hit == 0)
	{
		move_ray_one_step(r);
		if (is_ray_outside_map(game))
			break ;
		check_ray_tile(game);
	}
}

/*  ============================================================    */

// Calculer rojection du mur

void	compute_wall_projection(t_game *game)
{
	t_raycasting	*r;
	t_player		*p;

	r = &game->ray;
	p = &game->parsing.player;
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - p->pos_x
				+ (1 - r->step_x) / 2) / r->ray_dir_x;
	else
		r->perp_wall_dist = (r->map_y - p->pos_y
				+ (1 - r->step_y) / 2) / r->ray_dir_y;
	r->line_height = (int)(WIN_HEIGHT / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + WIN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + WIN_HEIGHT / 2;
	if (r->draw_end >= WIN_HEIGHT)
		r->draw_end = WIN_HEIGHT - 1;
}

/*  ============================================================    */

// Calculer tex_x

void	compute_tex_x(t_game *game, t_texture *tex)
{
	t_raycasting	*r;
	t_player		*p;

	r = &game->ray;
	p = &game->parsing.player;
	if (r->side == 0)
		r->wall_x = p->pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_x = p->pos_x + r->perp_wall_dist * r->ray_dir_x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * tex->width);
	if (r->side == 0 && r->ray_dir_x > 0)
		r->tex_x = tex->width - r->tex_x - 1;
	if (r->side == 1 && r->ray_dir_y < 0)
		r->tex_x = tex->width - r->tex_x - 1;
	if (r->tex_x < 0)
		r->tex_x = 0;
	if (r->tex_x >= tex->width)
		r->tex_x = tex->width - 1;
}

/*  ============================================================    */

