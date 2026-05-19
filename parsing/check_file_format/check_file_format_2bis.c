/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format_2bis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 07:57:22 by w                 #+#    #+#             */
/*   Updated: 2026/05/19 12:57:54 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

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
