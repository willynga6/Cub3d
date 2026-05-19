/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:25:37 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/14 11:43:25 by otidahoh         ###   ########.fr       */
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
	char	c;

	if (!p || !p->player.flood_f_map || !res || !*res)
		return ;
	if (y < 0 || y >= p->final_maps.nb_lines)
		return ;
	if (!p->player.flood_f_map[y])
	{
		*res = false;
		return ;
	}
	if (x < 0 || x >= (int)ft_strlen(p->player.flood_f_map[y]))
	{
		*res = false;
		return ;
	}
	c = p->player.flood_f_map[y][x];
	if (c == ' ' || c == '\0')
	{
		*res = false;
		print_error("Open map (space leak)");
		return ;
	}
	if (c == '1' || c == 'F')
		return ;
	p->player.flood_f_map[y][x] = 'F';
	real_flood_fill(p, y +1, x, res);
	real_flood_fill(p, y -1, x, res);
	real_flood_fill(p, y, x +1, res);
	real_flood_fill(p, y, x -1, res);
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