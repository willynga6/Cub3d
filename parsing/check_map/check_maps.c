/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:52:29 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:12:35 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

int	get_number_of_lines(t_parsing *parsing)
{
	int	i;

	if (!parsing || !parsing->maps)
		return (0);
	i = 0;
	while (parsing->maps[i])
		i++;
	return (i);
}

/*	================================================================	*/

int	get_max_line_length(t_parsing *parsing)
{
	int	i;
	int	max_length;

	if (!parsing || !parsing->maps)
		return (0);
	i = 0;
	max_length = 0;
	while (parsing->maps[i])
	{
		if ((int)ft_strlen(parsing->maps[i]) > max_length)
			max_length = ft_strlen(parsing->maps[i]);
		i++;
	}
	return (max_length);
}

/*	================================================================	*/

bool	only_walls(t_parsing *parsing)
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
			if (parsing->maps[i][j] != '1' && parsing->maps[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/*	================================================================	*/
