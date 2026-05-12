/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:34:10 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/12 07:53:55 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

static void	extension_error_msg(void)
{
	print_error("Error: map extension has to be .cub");
}

/*	================================================================	*/

static bool	check_last_four_char(char *str, int index_max)
{
	if (ft_charcmp (str[index_max], 'b'))
		index_max--;
	else
		return (false);
	if (ft_charcmp (str[index_max], 'u'))
		index_max--;
	else
		return (false);
	if (ft_charcmp (str[index_max], 'c'))
		index_max--;
	else
		return (false);
	if (ft_charcmp (str[index_max], '.'))
		index_max--;
	else
		return (false);
	return (true);
}

/*	================================================================	*/

static bool	check_extension(char *str)
{
	int	i;
	int	last_index;

	i = 0;
	if (!str)
	{
		print_error("Error: MAP Addresse not found");
		return (false);
	}
	while (str[i])
		i++;
	i--;
	last_index = i;
	if (check_last_four_char (str, last_index))
		return (true);
	else
		return (false);
}

/*	================================================================	*/

bool	is_valid_extension(t_parsing *parsing)
{
	char	*path_map;

	if (!parsing)
	{
		print_error("Error: bad structure adress");
		return (false);
	}
	path_map = parsing->maps_path;
	if (!check_extension (path_map))
	{
		extension_error_msg ();
		return (false);
	}
	else
		return (true);
}
