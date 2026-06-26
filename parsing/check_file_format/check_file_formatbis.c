/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_formatbis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:01:38 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 20:41:22 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*  =============================================================== */

static bool	mandatory_not_door(char **maps)
{
	int	x;
	int	y;

	if (!maps)
	{
		print_error ("MAP introuvable !\n");
		return (false);
	}
	x = 0;
	while (maps[x])
	{
		y = 0;
		while (maps[x][y])
		{
			if (maps[x][y] == 'D' || maps[x][y] == 'd')
			{
				print_error ("Door not authorized in mandatory part !\n");
				return (false);
			}
			y++;
		}
		x++;
	}
	return (true);
}

/*  =============================================================== */

static bool	check_mapfile_firt_part(t_parsing *parsing, int *i)
{
	if (!mandatory_not_door (parsing->maps))
		return (false);
	jump_empty_line(parsing, i);
	if (is_empty_file(parsing))
		return (required_format(), false);
	if (!am_i_in_texture_part(parsing, i))
		return (required_format(), false);
	if (!texture_case(parsing, i))
		return (false);
	return (true);
}

/*  =============================================================== */

bool	check_the_mapfile_format(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (!parsing || !parsing->maps)
		return (print_error("Error: bad structure adress"), false);
	if (!check_mapfile_firt_part (parsing, &i))
		return (false);
	jump_empty_line(parsing, &i);
	if (!am_i_in_color_part(parsing, &i))
		return (required_format(), false);
	if (!color_case(parsing, &i))
		return (false);
	jump_empty_line(parsing, &i);
	if (!map_case(parsing, &i))
		return (false);
	if (!quick_check_map_format(parsing))
		return (false);
	if (!init_map(parsing))
		return (false);
	return (true);
}
