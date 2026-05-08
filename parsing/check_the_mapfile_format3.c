/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_mapfile_format3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:21:44 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/08 12:43:39 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	double_no_texture(t_parsing *parsing, char *line, int *i)
{
	if (is_no_texture_part(line, i))
	{
		if (parsing->contain_no_texture)
		{
			printf ("Error: double NO texture\n");
			return (true);
		}
		parsing->contain_no_texture = true;
		return (true);
	}
	return (false);
}

/*	================================================================	*/

bool	double_so_texture(t_parsing *parsing, char *line, int *i)
{
	if (is_so_texture_part(line, i))
	{
		if (parsing->contain_so_texture)
		{
			printf ("Error: double SO texture\n");
			return (true);
		}
		parsing->contain_so_texture = true;
		return (true);
	}
	return (false);
}

/*	================================================================	*/

bool	double_we_texture(t_parsing *parsing, char *line, int *i)
{
	if (is_we_texture_part(line, i))
	{
		if (parsing->contain_we_texture)
		{
			printf ("Error: double WE texture\n");
			return (true);
		}
		parsing->contain_we_texture = true;
		return (true);
	}
	return (false);
}

/*	================================================================	*/

bool	double_ea_texture(t_parsing *parsing, char *line, int *i)
{
	if (is_ea_texture_part(line, i))
	{
		if (parsing->contain_ea_texture)
		{
			printf ("Error: double EA texture\n");
			return (true);
		}
		parsing->contain_ea_texture = true;
		return (true);
	}
	return (false);
}

/*	================================================================	*/