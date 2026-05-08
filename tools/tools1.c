/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 07:59:25 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/08 12:51:43 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

/*	================================================================	*/

bool	ft_charcmp(const char c1, const char c2)
{
	if (c1 == c2)
		return (true);
	else
		return (false);
}

/*	================================================================	*/

void	display_parsing(const t_parsing *parsing)
{
	if (!parsing)
	{
		printf("Error: bad structure adress\n");
		return ;
	}
	printf("==== PARSING DEBUG ====\n");
	printf("ac: %d\n", parsing->ac);
	printf("maps_path: %s\n", parsing->maps_path ? parsing->maps_path :
		"(null)");
	printf("maps ptr: %p\n", (void *)parsing->maps);
	printf("lst_malloc ptr: %p\n", (void *)parsing->lst_malloc);
	printf("fd_map: %d\n", parsing->fd_map);
	printf("nb_lines: %d\n", parsing->nb_lines);
	printf("no_texture: %s\n", parsing->no_texture ? parsing->no_texture :
		"(null)");
	printf("so_texture: %s\n", parsing->so_texture ? parsing->so_texture :
		"(null)");
	printf("we_texture: %s\n", parsing->we_texture ? parsing->we_texture :
		"(null)");
	printf("ea_texture: %s\n", parsing->ea_texture ? parsing->ea_texture :
		"(null)");
	printf("contain_no_texture: %d\n", parsing->contain_no_texture);
	printf("contain_so_texture: %d\n", parsing->contain_so_texture);
	printf("contain_we_texture: %d\n", parsing->contain_we_texture);
	printf("contain_ea_texture: %d\n", parsing->contain_ea_texture);
	printf("am_i_in_map: %d\n", parsing->am_i_in_map);
	printf("am_i_in_color: %d\n", parsing->am_i_in_color);
	printf("am_i_in_texture: %d\n", parsing->am_i_in_texture);
	printf("=======================\n");
}

/*	================================================================	*/

void	display_maps(char **maps)
{
	int	i;

	if (!maps)
	{
		printf("Error: bad maps adress\n");
		return ;
	}
	i = 0;
	while (maps[i])
	{
		printf("maps[%d]: %s", i, maps[i]);
		i++;
	}
}

/*	================================================================	*/

bool	is_space(char c)
{
	if (c >= 9 && c <= 13)
		return (true);
	else
		return (false);
}

/*	================================================================	*/

bool	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (true);
	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}
