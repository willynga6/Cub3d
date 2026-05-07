/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 07:17:12 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/07 07:51:47 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

/*	================================================================	*/

static bool	init_int_value(int ac, char **av, t_parsing *parsing)
{
	if (!parsing || !av)
	{
		printf ("Error: bad structure adress\n");
		return (false);
	}
	if (ac != 2)
	{
		printf("Program need two arguments to run: ./cub3D path/of/map.cub\n");
		return (false);
	}
	parsing->ac = ac;
	parsing->fd_map = open (av[1], O_RDONLY);
	if (parsing->fd_map < 0)
	{
		perror ("Error to open the map:");
		return (false);
	}
	return (true);
}

/*	================================================================	*/

static bool	init_char_value(char **av, t_parsing *parsing)
{
	if (!parsing || !av)
	{
		printf ("Error: bad structure adress\n");
		return (false);
	}
	parsing->maps_path = av[1];
	return (true);
}

/*	================================================================	*/

static void	init_bool_value(t_parsing *parsing)
{
	parsing->contain_no_texture = false;
	parsing->contain_so_texture = false;
	parsing->contain_we_texture = false;
	parsing->contain_ea_texture = false;
	parsing->am_i_in_map = false;
	parsing->am_i_in_color = false;
	parsing->am_i_in_texture = false;
}

/*	================================================================	*/

bool	init_parsing(char **av, int ac, t_parsing *parsing)
{
	if (!init_int_value (ac, av, parsing))
		return (false);
	if (!init_char_value (av, parsing))
		return (false);
	init_bool_value (parsing);
	return (true);
}
