/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:35:49 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/10 10:17:19 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

int	main(int ac, char **av)
{
	t_parsing	parsing;
	t_malloc	*lst_malloc;

	lst_malloc = NULL;
	if (!init_lst_malloc(&lst_malloc))
		return (1);
	if (!init_parsing (av, ac, &parsing, &lst_malloc))
		return (free_lst_malloc(&lst_malloc), 1);
	check_the_mapfile_format(&parsing);
	//display_parsing(&parsing);
	free_lst_malloc(&lst_malloc);
	close(parsing.fd_map);
	return (0);
}
