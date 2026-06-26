/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:50:47 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 17:32:00 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	ft_charcmp(const char c1, const char c2)
{
	if (c1 == c2)
		return (true);
	else
		return (false);
}

/*	================================================================	*/
/*
void	display_parsing(const t_parsing *parsing)
{
	int	i;

	if (!parsing)
	{
		print_error("Error: bad structure adress");
		return;
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
	printf("f_color: %s\n", parsing->f_color ? parsing->f_color : "(null)");
	printf("c_color: %s\n", parsing->c_color ? parsing->c_color : "(null)");
	printf("contain_no_texture: %d\n", parsing->contain_no_texture);
	printf("contain_so_texture: %d\n", parsing->contain_so_texture);
	printf("contain_we_texture: %d\n", parsing->contain_we_texture);
	printf("contain_ea_texture: %d\n", parsing->contain_ea_texture);
	printf("contain_f_color: %d\n", parsing->contain_f_color);
	printf("contain_c_color: %d\n", parsing->contain_c_color);
	printf("am_i_in_map: %d\n", parsing->am_i_in_map);
	printf("am_i_in_color: %d\n", parsing->am_i_in_color);
	printf("am_i_in_texture: %d\n", parsing->am_i_in_texture);
	printf("---- maps table ----\n");
	if (!parsing->maps)
		printf("(null)\n");
	else
	{
		i = 0;
		while (parsing->maps[i])
		{
			if (i < 10)
				printf("maps[%d]\t\t: %s", i, parsing->maps[i]);
			else
				printf("maps[%d]\t: %s", i, parsing->maps[i]);
			i++;
}
}
	printf("=======================\n");
}
*/

/*	================================================================	*/

void	display_maps(char **maps)
{
	int	i;

	if (!maps)
	{
		print_error("Error: bad maps adress");
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
	if (c == ' ' || (c >= 9 && c <= 13))
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

/*	================================================================	*/

bool	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}
