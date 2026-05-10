/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_mapfile_format.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 08:42:11 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/10 10:06:09 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	in_nothing_part(t_parsing *parsing)
{
	if (parsing->am_i_in_map)
		return (false);
	if (parsing->am_i_in_color)
		return (false);
	if (parsing->am_i_in_texture)
		return (false);
	return (true);
}

/*	================================================================	*/

bool	is_empty_file(t_parsing *parsing)
{
	int	i;

	i = 0;
	while (parsing->maps[i])
	{
		if (!is_empty_line(parsing->maps[i]))
			return (false);
		i++;
	}
	print_error("Error: the file is empty");
	return (true);
}

/*	================================================================	*/

void	jump_empty_line(t_parsing *parsing, int *i)
{
	while (parsing->maps[*i] && is_empty_line(parsing->maps[*i]))
		(*i)++;
}

/*	================================================================	*/

bool	am_i_in_texture_part(t_parsing *parsing, int *i)
{
	char	first_two_char[3];

	first_two_char[0] = parsing->maps[*i][0];
	first_two_char[1] = parsing->maps[*i][1];
	first_two_char[2] = '\0';
	if (!ft_strcmp(first_two_char, "NO") || !ft_strcmp(first_two_char, "SO")
		|| !ft_strcmp(first_two_char, "WE") || !ft_strcmp(first_two_char, "EA"))
	{
		parsing->am_i_in_texture = true;
		return (true);
	}
	if (all_texture_part_is_here(parsing))
	{
		parsing->am_i_in_texture = false;
		return (true);
	}
	return (false);
}

bool	mute_am_i_in_texture_part(t_parsing *parsing, int *i)
{
	char	first_two_char[3];

	first_two_char[0] = parsing->maps[*i][0];
	first_two_char[1] = parsing->maps[*i][1];
	first_two_char[2] = '\0';
	if (!ft_strcmp(first_two_char, "NO") || !ft_strcmp(first_two_char, "SO")
		|| !ft_strcmp(first_two_char, "WE") || !ft_strcmp(first_two_char, "EA"))
	{
		parsing->am_i_in_texture = true;
		return (true);
	}
	if (mute_all_texture_part_is_here(parsing))
	{
		parsing->am_i_in_texture = false;
		return (true);
	}
	return (false);
}

/*	================================================================	*/

bool	check_the_mapfile_format(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (!parsing || !parsing->maps)
	{
		print_error("Error: bad structure adress");
		return (false);
	}
	jump_empty_line(parsing, &i);
	if (is_empty_file(parsing))
		return (required_format(), false);
	if (!is_no_texture_part(parsing->maps[i])
		&& !is_so_texture_part(parsing->maps[i])
		&& !is_we_texture_part(parsing->maps[i])
		&& !is_ea_texture_part(parsing->maps[i]))
		return (required_format(), false);
	if (!am_i_in_texture_part(parsing, &i))
		return (false);
	if (!texture_case(parsing, &i))
		return (false);
	jump_empty_line(parsing, &i);
	if (!is_f_color_part(parsing->maps[i]) && !is_c_color_part(parsing->maps[i]))
		return (required_format(), false);
	if (!color_case(parsing, &i))
		return (false);
	jump_empty_line(parsing, &i);
	if (!map_case(parsing, &i))
		return (false);
	return (true);
}

/*	================================================================	*/