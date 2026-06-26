/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:52:25 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:11:33 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	check_first_and_last_line(t_parsing *parsing, int nb_lines)
{
	int	i;

	if (!parsing || !parsing->maps || nb_lines < 3)
		return (false);
	i = 0;
	while (parsing->maps[0][i])
	{
		if (parsing->maps[0][i] != '1' && parsing->maps[0][i] != ' ')
			return (print_error (FIRST_LINE_ERROR), false);
		i++;
	}
	i = 0;
	while (parsing->maps[nb_lines - 1][i])
	{
		if (parsing->maps[nb_lines - 1][i] != '1'
			&& parsing->maps[nb_lines - 1][i] != ' ')
			return (print_error (LAST_LINE_ERROR), false);
		i++;
	}
	return (true);
}

/*	================================================================	*/

bool	only_one_player(t_parsing *parsing)
{
	int	i;
	int	j;
	int	player_count;

	if (!parsing || !parsing->maps)
		return (false);
	i = 0;
	player_count = 0;
	while (parsing->maps[i])
	{
		j = 0;
		while (parsing->maps[i][j])
		{
			if (parsing->maps[i][j] == 'N' || parsing->maps[i][j] == 'S'
				|| parsing->maps[i][j] == 'E' || parsing->maps[i][j] == 'W')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (print_error("Error: Map must contain exactly one player"),
			false);
	return (true);
}

/*	================================================================	*/

bool	quick_check_map_format(t_parsing *parsing)
{
	const int	nb_lines = get_number_of_lines(parsing);
	const int	max_line_length = get_max_line_length(parsing);

	if (!parsing || !parsing->maps)
		return (false);
	if (nb_lines < 3)
		return (print_error("Error: Map must have at least 3 lines"), false);
	if (max_line_length < 3)
		return (print_error("Error: Map lines must have at least 3 characters"),
			false);
	if (!check_first_and_last_line(parsing, nb_lines))
		return (false);
	if (!only_one_player(parsing))
		return (false);
	return (true);
}

/*	================================================================	*/
