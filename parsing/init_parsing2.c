/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:13:59 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/08 10:25:53 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

char	**get_maps(t_parsing *parsing, t_malloc **lst_malloc)
{
	char	**maps;
	int		fd;
	int		i;

	maps = malloc_remix(lst_malloc, sizeof(char *) * (parsing->nb_lines + 1));
	if (!maps)
		return (NULL);
	fd = open(parsing->maps_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (i < parsing->nb_lines)
	{
		maps[i] = get_next_line(lst_malloc, fd);
		i++;
	}
	maps[i] = NULL;
	close(fd);
	return (maps);
}