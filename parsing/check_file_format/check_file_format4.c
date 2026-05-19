/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 07:54:17 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/19 17:37:33 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	no_case(t_parsing *parsing, char *line, int *i)
{
	char	**value;

	if (!parsing || !line || !i)
		return (false);
	if (!am_i_in_texture_part(parsing, i))
		return (false);
	if (is_no_texture_part(line))
	{
		if (!double_no_texture(parsing, line))
		{
			parsing->contain_no_texture = true;
			value = ft_split(parsing->lst_malloc, line, ' ');
			if (!value)
				return (false);
			parsing->no_texture = ft_strtrim(value[1], " \t\n");
			return (true);
		}
		return (false);
	}
	return (true);
}

/*	================================================================	*/

bool	so_case(t_parsing *parsing, char *line, int *i)
{
	char	**value;

	if (!parsing || !line || !i)
		return (false);
	if (!am_i_in_texture_part(parsing, i))
		return (false);
	if (is_so_texture_part(line))
	{
		if (!double_so_texture(parsing, line))
		{
			parsing->contain_so_texture = true;
			value = ft_split(parsing->lst_malloc, line, ' ');
			if (!value)
				return (false);
			parsing->so_texture = ft_strtrim(value[1], " \t\n");
			return (true);
		}
		return (false);
	}
	return (true);
}

/*	================================================================	*/

bool	we_case(t_parsing *parsing, char *line, int *i)
{
	char	**value;

	if (!parsing || !line || !i)
		return (false);
	if (!am_i_in_texture_part(parsing, i))
		return (false);
	if (is_we_texture_part(line))
	{
		if (!double_we_texture(parsing, line))
		{
			parsing->contain_we_texture = true;
			value = ft_split(parsing->lst_malloc, line, ' ');
			if (!value)
				return (false);
			parsing->we_texture = ft_strtrim(value[1], " \t\n");
			return (true);
		}
		return (false);
	}
	return (true);
}

/*	================================================================	*/

bool	ea_case(t_parsing *parsing, char *line, int *i)
{
	char	**value;

	if (!parsing || !line || !i)
		return (false);
	if (!am_i_in_texture_part(parsing, i))
		return (false);
	if (is_ea_texture_part(line))
	{
		if (!double_ea_texture(parsing, line))
		{
			parsing->contain_ea_texture = true;
			value = ft_split(parsing->lst_malloc, line, ' ');
			if (!value)
				return (false);
			parsing->ea_texture = ft_strtrim(value[1], " \t\n");
			return (true);
		}
		return (false);
	}
	return (true);
}

/*	================================================================	*/

bool	texture_case(t_parsing *parsing, int *i)
{
	while (parsing->maps[*i] && mute_am_i_in_texture_part(parsing, i)
		&& parsing->am_i_in_texture)
	{
		if (!no_case(parsing, parsing->maps[*i], i))
			return (false);
		if (!so_case(parsing, parsing->maps[*i], i))
			return (false);
		if (!we_case(parsing, parsing->maps[*i], i))
			return (false);
		if (!ea_case(parsing, parsing->maps[*i], i))
			return (false);
		(*i)++;
	}
	if (!all_texture_part_is_here(parsing))
	{
		print_error("Error: the file must contain 4 textures information");
		return (false);
	}
	return (true);
}
