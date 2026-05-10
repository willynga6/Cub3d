/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_mapfile_format2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:55:45 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/10 09:52:19 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	===============================================================	*/

bool	is_no_texture_part(char *line)
{
	if (!line)
		return (false);
	if (line[0] == 'N' && line[1] == 'O')
		return (true);
	return (false);
}

/*	===============================================================	*/

bool	is_so_texture_part(char *line)
{
	if (!line)
		return (false);
	if (line[0] == 'S' && line[1] == 'O')
		return (true);
	return (false);
}

/*	===============================================================	*/

bool	is_we_texture_part(char *line)
{
	if (!line)
		return (false);
	if (line[0] == 'W' && line[1] == 'E')
		return (true);
	return (false);
}

/*	===============================================================	*/

bool	is_ea_texture_part(char *line)
{
	if (!line)
		return (false);
	if (line[0] == 'E' && line[1] == 'A')
		return (true);
	return (false);
}

/*	===============================================================	*/

bool	all_texture_part_is_here(t_parsing *parsing)
{
	if (!parsing)
		return (false);
	if (mute_all_texture_part_is_here(parsing))
		return (true);
	if (!parsing->contain_no_texture)
		print_error("Error: NO texture is missing");
	if (!parsing->contain_so_texture)
		print_error("Error: SO texture is missing");
	if (!parsing->contain_we_texture)
		print_error("Error: WE texture is missing");
	if (!parsing->contain_ea_texture)
		print_error("Error: EA texture is missing");
	return (false);
}

/*	===============================================================	*/

bool	mute_all_texture_part_is_here(t_parsing *parsing)
{
	if (!parsing->contain_no_texture)
		return (false);
	if (!parsing->contain_so_texture)
		return (false);
	if (!parsing->contain_we_texture)
		return (false);
	if (!parsing->contain_ea_texture)
		return (false);
	return (true);
}
