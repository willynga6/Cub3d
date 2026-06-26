/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:17:16 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 14:17:19 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_p(t_player *p, double rot_spd)
{
	double	prev_dir_x;
	double	prev_plane_x;

	prev_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_spd) - p->dir_y * sin(rot_spd);
	p->dir_y = prev_dir_x * sin(rot_spd) + p->dir_y * cos(rot_spd);
	prev_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_spd) - p->plane_y * sin(rot_spd);
	p->plane_y = prev_plane_x * sin(rot_spd) + p->plane_y * cos(rot_spd);
}

int	mouse_move(int x, int y, t_game *game)
{
	int			delta_x;
	double		center_x;

	if (!game)
		return (0);
	(void)y;
	center_x = WIN_WIDTH / 2;
	delta_x = x - center_x;
	if (delta_x != 0)
		rotate_p(&game->parsing.player, delta_x * 0.001);
	mlx_mouse_move(game->mlx.mlx, game->mlx.win, center_x, WIN_HEIGHT / 2);
	if (delta_x == 0)
		return (0);
	return (0);
}
