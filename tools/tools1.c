/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 07:59:25 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/07 09:11:54 by wngambi          ###   ########.fr       */
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
	printf("ac: %d\n", parsing->ac);
	printf("maps_path: %s\n", parsing->maps_path ? parsing->maps_path :
		"(null)");
	printf("fd_map: %d\n", parsing->fd_map);
	printf("contain_no_texture: %d\n", parsing->contain_no_texture);
	printf("contain_so_texture: %d\n", parsing->contain_so_texture);
	printf("contain_we_texture: %d\n", parsing->contain_we_texture);
	printf("contain_ea_texture: %d\n", parsing->contain_ea_texture);
	printf("am_i_in_map: %d\n", parsing->am_i_in_map);
	printf("am_i_in_color: %d\n", parsing->am_i_in_color);
	printf("am_i_in_texture: %d\n", parsing->am_i_in_texture);
}

/*	================================================================	*/
