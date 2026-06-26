/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:53:34 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:01:02 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

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
	return (false);
}
