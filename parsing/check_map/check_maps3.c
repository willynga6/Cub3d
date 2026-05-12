/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:00:00 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/12 09:49:08 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

static bool	redefine_line(t_parsing *parsing, int line_index,
	int max_length)
{
	int		i;
	char	*new_line;

	if (!parsing || !parsing->maps || line_index < 0 || max_length < 0)
		return (false);
	new_line = malloc_remix(parsing->lst_malloc,
			sizeof(char) * (max_length + 1));
	if (!new_line)
		return (false);
	i = 0;
	while (parsing->maps[line_index][i])
	{
		new_line[i] = parsing->maps[line_index][i];
		i++;
	}
	while (i < max_length)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	parsing->maps[line_index] = new_line;
	return (true);
}

/*	================================================================	*/

static bool	fill_new_map(t_parsing *parsing)
{
	int	i;

	i = 0;
	while (i < parsing->nb_lines)
	{
		if (!redefine_line(parsing, i, parsing->final_maps.max_line_length))
			return (false);
		parsing->final_maps.map[i] = parsing->maps[i];
		i++;
	}
	parsing->final_maps.map[parsing->nb_lines] = NULL;
	return (true);
}

/*	================================================================	*/

static bool	redefine_map(t_parsing *parsing)
{
	if (!parsing || !parsing->maps)
		return (false);
	parsing->final_maps.map = malloc_remix(parsing->lst_malloc,
			sizeof(char *) * (parsing->nb_lines + 1));
	if (!parsing->final_maps.map)
		return (false);
	return (fill_new_map(parsing));
}

/*	================================================================	*/

bool	init_map(t_parsing *parsing)
{
	if (!parsing || !parsing->maps)
		return (false);
	parsing->nb_lines = get_number_of_lines(parsing);
	if (parsing->nb_lines == 0)
		return (print_error("Error: map is empty"), false);
	parsing->final_maps.nb_lines = parsing->nb_lines;
	parsing->final_maps.max_line_length = get_max_line_length(parsing);
	if (!redefine_map(parsing))
		return (false);
	return (true);
}

/*	================================================================	*/

bool	maj_position_player(t_parsing *parsing)
{
	int	i;
	int	j;

	if (!parsing || !parsing->maps)
		return (false);
	i = 0;
	while (parsing->maps[i])
	{
		j = 0;
		while (parsing->maps[i][j])
		{
			if (parsing->maps[i][j] == 'N' || parsing->maps[i][j] == 'S'
				|| parsing->maps[i][j] == 'E' || parsing->maps[i][j] == 'W')
			{
				parsing->player.y = i;
				parsing->player.x = j;
				return (true);
			}
			j++;
		}
		i++;
	}
	print_error("Error: player position not found in the map");
	return (false);
}
