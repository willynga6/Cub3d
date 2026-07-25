/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:02:19 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 17:33:44 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

static bool	check_the_mapfile_format_bonus(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (!parsing || !parsing->maps)
		return (print_error("Error: bad structure adress"), false);
	jump_empty_line(parsing, &i);
	if (is_empty_file(parsing))
		return (required_format(), false);
	if (!am_i_in_texture_part(parsing, &i))
		return (required_format(), false);
	if (!texture_case(parsing, &i))
		return (false);
	jump_empty_line(parsing, &i);
	if (!am_i_in_color_part(parsing, &i))
		return (required_format(), false);
	if (!color_case(parsing, &i))
		return (false);
	jump_empty_line(parsing, &i);
	if (!map_case(parsing, &i))
		return (false);
	if (!quick_check_map_format(parsing))
		return (false);
	if (!init_map(parsing))
		return (false);
	return (true);
}

bool	parsing_bonus(t_game *game, char **av, int ac, t_malloc **lst_malloc)
{
	if (ac != 2)
	{
		printf("Program need two arguments to run: ./cub3D path/of/map.cub\n");
		return (false);
	}
	if (!check_extension(av[1]))
		return (false);
	if (!init_lst_malloc(lst_malloc))
		return (false);
	if (!init_parsing(av, ac, &game->parsing, lst_malloc))
		return (clean_and_close(lst_malloc, game->parsing.fd_map), false);
	if (!check_the_mapfile_format_bonus(&game->parsing))
		return (clean_and_close(lst_malloc, game->parsing.fd_map), false);
	if (!flood_fill(&game->parsing, lst_malloc))
		return (clean_and_close(lst_malloc, game->parsing.fd_map), false);
	extract_player(&game->parsing);
	return (true);
}
