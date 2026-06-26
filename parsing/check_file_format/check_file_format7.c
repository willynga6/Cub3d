/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format7.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:52:56 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:10:21 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

static bool	f_color_case(t_parsing *parsing, int *i)
{
	if (!parsing || !i || !parsing->maps || !parsing->maps[*i])
		return (false);
	if (parsing->contain_f_color)
		return (print_error("Error: double F color"), false);
	if (!save_color_value(parsing, parsing->maps[*i], true))
		return (print_error("Error: invalid F color format"), false);
	parsing->contain_f_color = true;
	return (true);
}

static bool	c_color_case(t_parsing *parsing, int *i)
{
	if (!parsing || !i || !parsing->maps || !parsing->maps[*i])
		return (false);
	if (parsing->contain_c_color)
		return (print_error("Error: double C color"), false);
	if (!save_color_value(parsing, parsing->maps[*i], false))
		return (print_error("Error: invalid C color format"), false);
	parsing->contain_c_color = true;
	return (true);
}

bool	color_case(t_parsing *parsing, int *i)
{
	if (!parsing || !i)
		return (false);
	while (parsing->maps[*i]
		&& (is_f_color_part(parsing->maps[*i])
			|| is_c_color_part(parsing->maps[*i])))
	{
		if (is_f_color_part(parsing->maps[*i]))
		{
			if (!f_color_case(parsing, i))
				return (false);
		}
		else if (is_c_color_part(parsing->maps[*i]))
		{
			if (!c_color_case(parsing, i))
				return (false);
		}
		else
			return (false);
		(*i)++;
	}
	if (!all_color_part_is_here(parsing))
		return (false);
	return (true);
}

/*	================================================================	*/

static bool	is_map_line(char *line)
{
	int	j;

	if (!line)
		return (false);
	j = 0;
	while (line[j])
	{
		if (line[j] == '0' || line[j] == '1' || line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'W'
			|| line[j] == 'D' || line[j] == ' ')
			j++;
		else
			return (false);
	}
	return (true);
}

/*	================================================================	*/

bool	map_case(t_parsing *parsing, int *i)
{
	int	map_start;

	if (!parsing || !i || !parsing->maps || !parsing->maps[*i])
		return (print_error("Error: map is missing"), false);
	convert_new_line_into_eol(parsing);
	map_start = *i;
	parsing->am_i_in_map = true;
	while (parsing->maps[*i] && !is_empty_line(parsing->maps[*i]))
	{
		if (!is_map_line(parsing->maps[*i]))
			return (print_error("Error: invalid map character"), false);
		(*i)++;
	}
	jump_empty_line(parsing, i);
	if (parsing->maps[*i])
		return (print_error("Error: invalid content after map"), false);
	parsing->maps = &parsing->maps[map_start];
	return (true);
}
