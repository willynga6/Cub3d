/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format_2bis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:53:39 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:10:43 by wngambi          ###   ########.fr       */
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
