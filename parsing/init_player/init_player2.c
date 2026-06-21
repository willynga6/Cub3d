/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:42:27 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/21 16:54:30 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "structure.h"

/*  ================================================    */

static void	north_case_direction(t_player *player)
{
	if (!player)
		return ;
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

/*  ================================================    */

static void	south_case_direction(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

/*  ================================================    */

static void	est_case_direction(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

/*  ================================================    */

static void	west_case_direction(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

/*  ================================================    */

void	init_player_dir(t_player *p, char c)
{
	if (c == 'N')
		north_case_direction (p);
	else if (c == 'S')
		south_case_direction (p);
	else if (c == 'E')
		est_case_direction (p);
	else if (c == 'W')
		west_case_direction (p);
}
