/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:25:37 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/13 13:49:22 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

/*	================================================================	*/

void	replace_pos_by_zero(t_parsing *parsing)
{
	if (!parsing || !parsing->maps || !parsing->player.flood_f_map)
		return ;
	parsing->player.flood_f_map[parsing->player.map_y][parsing->player.map_x] = '0';
}

/*	================================================================	*/

bool	set_up_flood_fill(t_parsing *parsing, t_malloc **lst_malloc)
{
	if (!parsing || !lst_malloc)
		return (false);
	if (!maj_position_player(parsing))
		return (false);
	parsing->player.flood_f_map = duplicate_maps(parsing, lst_malloc);
	if (!parsing->player.flood_f_map)
	{
		print_error("Error: failed to duplicate the map for flood fill");
		return (false);
	}
	return (true);
}

/*	================================================================	*/

void	real_flood_fill(t_parsing *p, int y, int x, bool *res)
{
	char	actual_char;

	if (!p || !p->final_maps.map || !res || *res == false)
		return ;
	if (y < 0 || x < 0 || y >= p->final_maps.nb_lines
		|| x >= (int)ft_strlen(p->final_maps.map[y]))
	{
		*res = false;
		return ;
	}
	actual_char = p->final_maps.map[y][x];
	if (actual_char == ' ')
	{
		*res = false;
		print_error("Error: Empty space accessible by the player in the map");
		return ;
	}
	if (actual_char == '1' || actual_char == 'F')
		return ;
	p->final_maps.map[y][x] = 'F';
	real_flood_fill(p, y + 1, x, res);
	real_flood_fill(p, y - 1, x, res);
	real_flood_fill(p, y, x + 1, res);
	real_flood_fill(p, y, x - 1, res);
}

/*	================================================================	*/

bool	flood_fill(t_parsing *parsing, t_malloc **lst_malloc)
{
	bool	res_flood;

	res_flood = true;
	if (!parsing || !lst_malloc)
		return (false);
	if (!set_up_flood_fill(parsing, lst_malloc))
		return (false);
	real_flood_fill(parsing, parsing->player.map_y,
		parsing->player.map_x, &res_flood);
	if (!res_flood)
		return (false);
	return (res_flood);
}

/*	================================================================	*/