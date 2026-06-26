/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:52:03 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:15:10 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

static bool	init_int_value(int ac, char **av, t_parsing *parsing,
	t_malloc **lst_malloc)
{
	if (!parsing || !av)
	{
		print_error("Error: bad structure adress");
		return (false);
	}
	if (ac != 2)
	{
		printf("Program need two arguments to run: ./cub3D path/of/map.cub\n");
		return (false);
	}
	parsing->ac = ac;
	parsing->lst_malloc = lst_malloc;
	parsing->fd_map = open (av[1], O_RDONLY);
	if (parsing->fd_map < 0)
	{
		perror ("Error to open the map:");
		return (false);
	}
	parsing->nb_lines = count_lines(av[1], lst_malloc);
	if (parsing->nb_lines <= 0)
	{
		printf("Error the file is empty or can't be read\n");
		return (false);
	}
	return (true);
}

/*	================================================================	*/

static bool	init_char_value(char **av, t_parsing *parsing,
	t_malloc **lst_malloc)
{
	if (!parsing || !av)
	{
		print_error("Error: bad structure adress");
		return (false);
	}
	parsing->maps_path = av[1];
	parsing->maps = get_maps(parsing, lst_malloc);
	if (!parsing->maps)
	{
		print_error("Error: failed to get the maps");
		return (false);
	}
	parsing->no_texture = NULL;
	parsing->so_texture = NULL;
	parsing->we_texture = NULL;
	parsing->ea_texture = NULL;
	parsing->f_color = NULL;
	parsing->c_color = NULL;
	return (true);
}

/*	================================================================	*/

static void	init_bool_value(t_parsing *parsing)
{
	parsing->contain_no_texture = false;
	parsing->contain_so_texture = false;
	parsing->contain_we_texture = false;
	parsing->contain_ea_texture = false;
	parsing->contain_f_color = false;
	parsing->contain_c_color = false;
	parsing->am_i_in_map = false;
	parsing->am_i_in_color = false;
	parsing->am_i_in_texture = false;
}

/*	================================================================	*/

bool	init_parsing(char **av, int ac,
	t_parsing *parsing, t_malloc **lst_malloc)
{
	if (!parsing || !av || !lst_malloc)
	{
		print_error("Error: bad structure adress");
		return (false);
	}
	if (!init_int_value (ac, av, parsing, lst_malloc))
		return (false);
	if (!init_char_value (av, parsing, lst_malloc))
		return (false);
	init_bool_value (parsing);
	return (true);
}

/*	================================================================	*/

int	count_lines(char *filename, t_malloc **lst_malloc)
{
	int		fd;
	int		line_count;
	char	*line;

	if (!filename || !lst_malloc)
		return (-1);
	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(lst_malloc, fd);
	while (line)
	{
		line_count++;
		line = get_next_line(lst_malloc, fd);
	}
	close(fd);
	return (line_count);
}
