/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:34:10 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/07 08:40:40 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

static void	extension_error_msg(void)
{
	printf ("Error: map extension has to be .cub\n");
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
		printf ("Error: MAP Addresse not found\n");
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
		printf ("Error: bad structure adress\n");
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

/*	================================================================	*/
