/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_mapfile_format3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:21:44 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/10 09:45:47 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	double_no_texture(t_parsing *parsing, char *line)
{
	if (!parsing || !line)
		return (false);
	if (is_no_texture_part(line))
	{
		if (parsing->contain_no_texture)
		{
			print_error("Error: double NO texture");
			return (true);
		}
		parsing->contain_no_texture = true;
	}
	return (false);
}

/*	================================================================	*/

bool	double_so_texture(t_parsing *parsing, char *line)
{
	if (!parsing || !line)
		return (false);
	if (is_so_texture_part(line))
	{
		if (parsing->contain_so_texture)
		{
			print_error("Error: double SO texture");
			return (true);
		}
		parsing->contain_so_texture = true;
	}
	return (false);
}

/*	================================================================	*/

bool	double_we_texture(t_parsing *parsing, char *line)
{
	if (!parsing || !line)
		return (false);
	if (is_we_texture_part(line))
	{
		if (parsing->contain_we_texture)
		{
			print_error("Error: double WE texture");
			return (true);
		}
		parsing->contain_we_texture = true;
	}
	return (false);
}

/*	================================================================	*/

bool	double_ea_texture(t_parsing *parsing, char *line)
{
	if (!parsing || !line)
		return (false);
	if (is_ea_texture_part(line))
	{
		if (parsing->contain_ea_texture)
		{
			print_error("Error: double EA texture");
			return (true);
		}
		parsing->contain_ea_texture = true;
	}
	return (false);
}

/*	================================================================	*/