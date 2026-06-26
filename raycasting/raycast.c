/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:29:31 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 20:29:40 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "structure.h"

void	cast_ray(t_game *game)
{
	t_raycasting	*r;

	r = &game->ray;
	r->x = 0;
	while (r->x < WIN_WIDTH)
	{
		init_ray(game);
		init_dda(game);
		perform_dda(game);
		draw_wall_hit(game);
		draw_open_door_if_needed(game);
		r->x++;
	}
}