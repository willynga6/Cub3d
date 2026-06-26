/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:52:49 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:10:29 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	convert_new_line_into_eol(t_parsing *parsing)
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
			if (parsing->maps[i][j] == '\n' && parsing->maps[i][j + 1] == '\0')
				parsing->maps[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (true);
}
