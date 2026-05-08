/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_mapfile_format.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 08:42:11 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/08 12:44:31 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

bool	texture_case(t_parsing *parsing, int *i);
bool	all_texture_part_is_here(t_parsing *parsing);

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
	printf ("Error: the file is empty\n");
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
	printf ("Error: the file must start with texture information\n");
	return (false);
}


/*	================================================================	*/

bool	check_the_mapfile_format(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (!parsing || !parsing->maps)
		return (printf ("Error: bad structure adress\n"), false);
	if (is_empty_file(parsing))
		return (false);
	jump_empty_line(parsing, &i);
	if (!am_i_in_texture_part(parsing, &i))
		return (false);
	if (!texture_case(parsing, &i))
		return (false);
	return (true);
}

/*	================================================================	*/

bool	no_case(t_parsing *parsing, char *line, int *i)
{
	char	**value;

	if (!parsing || !line || !i)
		return (false);
	if (!am_i_in_texture_part(parsing, i))
		return (false);
	if (is_no_texture_part(line, i))
	{
		if (!double_no_texture(parsing, line, i))
		{
			parsing->contain_no_texture = true;
			value = ft_split(parsing->lst_malloc, line, ' ');
			if (!value)
				return (false);
			parsing->no_texture = value[1];
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
	if (is_so_texture_part(line, i))
	{
		if (!double_so_texture(parsing, line, i))
		{
			parsing->contain_so_texture = true;
			value = ft_split(parsing->lst_malloc, line, ' ');
			if (!value)
				return (false);
			parsing->so_texture = value[1];
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
	if (is_we_texture_part(line, i))
	{
		if (!double_we_texture(parsing, line, i))
		{
			parsing->contain_we_texture = true;
			value = ft_split(parsing->lst_malloc, line, ' ');
			if (!value)
				return (false);
			parsing->we_texture = value[1];
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
	if (is_ea_texture_part(line, i))
	{
		if (!double_ea_texture(parsing, line, i))
		{
			parsing->contain_ea_texture = true;
			value = ft_split(parsing->lst_malloc, line, ' ');
			if (!value)
				return (false);
			parsing->ea_texture = value[1];
			return (true);
		}
		return (false);
	}
	return (true);
}

/*	================================================================	*/

bool	texture_case(t_parsing *parsing, int *i)
{
	while (parsing->maps[*i] && parsing->am_i_in_texture)
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
		return (false);
	return (true);
}