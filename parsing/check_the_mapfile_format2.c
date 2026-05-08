/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_mapfile_format2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:55:45 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/08 12:40:04 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	===============================================================	*/

bool	is_no_texture_part(char *line, int *i)
{
	if (line[*i] == 'N' && line[*i + 1] == 'O')
		return (true);
	return (false);
}

/*	===============================================================	*/

bool	is_so_texture_part(char *line, int *i)
{
	if (line[*i] == 'S' && line[*i + 1] == 'O')
		return (true);
	return (false);
}

/*	===============================================================	*/

bool	is_we_texture_part(char *line, int *i)
{
	if (line[*i] == 'W' && line[*i + 1] == 'E')
		return (true);
	return (false);
}

/*	===============================================================	*/

bool	is_ea_texture_part(char *line, int *i)
{
	if (line[*i] == 'E' && line[*i + 1] == 'A')
		return (true);
	return (false);
}

/*	===============================================================	*/

bool	all_texture_part_is_here(t_parsing *parsing)
{
	if (!parsing->contain_no_texture)
	{
		printf ("Error: NO texture is missing\n");
		return (false);
	}
	if (!parsing->contain_so_texture)
	{
		printf ("Error: SO texture is missing\n");
		return (false);
	}
	if (!parsing->contain_we_texture)
	{
		printf ("Error: WE texture is missing\n");
		return (false);
	}
	if (!parsing->contain_ea_texture)
	{
		printf ("Error: EA texture is missing\n");
		return (false);
	}
	return (true);
}
