/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:35:49 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/07 09:24:41 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

int	main(int ac, char **av)
{
	t_parsing	parsing;
	t_malloc	*lst_malloc;

	lst_malloc = NULL;
	if (!init_parsing (av, ac, &parsing))
		return (1);
	free_lst_malloc(&lst_malloc);
	return (0);
}