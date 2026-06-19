/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 07:41:07 by w                 #+#    #+#             */
/*   Updated: 2026/06/19 14:52:45 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	is_c_color_part(char *line)
{
	if (!line)
		return (false);
	if (line[0] == 'C' && is_space(line[1]))
		return (true);
	return (false);
}

/*	================================================================	*/

bool	all_color_part_is_here(t_parsing *parsing)
{
	if (!parsing)
		return (false);
	if (mute_all_color_part_is_here(parsing))
		return (true);
	if (!parsing->contain_f_color)
		print_error("Error: F color is missing");
	if (!parsing->contain_c_color)
		print_error("Error: C color is missing");
	return (false);
}

/*	================================================================	*/

bool	mute_all_color_part_is_here(t_parsing *parsing)
{
	if (!parsing)
		return (false);
	if (!parsing->contain_f_color)
		return (false);
	if (!parsing->contain_c_color)
		return (false);
	return (true);
}

/*	================================================================	*/

bool	am_i_in_color_part(t_parsing *parsing, int *i)
{
	if (!parsing || !i || !parsing->maps || !parsing->maps[*i])
		return (false);
	if (is_f_color_part(parsing->maps[*i])
		|| is_c_color_part(parsing->maps[*i]))
	{
		parsing->am_i_in_color = true;
		return (true);
	}
	if (all_color_part_is_here(parsing))
	{
		parsing->am_i_in_color = false;
		return (true);
	}
	return (false);
}

/*	================================================================	*/