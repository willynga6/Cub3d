/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 09:35:23 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/10 09:58:45 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

/*	================================================================	*/

void	print_error(const char *message)
{
	if (!message)
		return ;
	if (isatty(STDERR_FILENO))
		fprintf(stderr, "\033[1;31m%s\033[0m\n", message);
	else
		fprintf(stderr, "%s\n", message);
}

/*	================================================================	*/

void	required_format(void)
{
	print_error("Error: The required .cub format is  :");
	printf ("\tPart 1: The textures paths\n\n");
	printf ("NO ./path_to_the_north_texture\n");
	printf ("SO ./path_to_the_south_texture\n");
	printf ("WE ./path_to_the_west_texture\n");
	printf ("EA ./path_to_the_east_texture\n");
	printf ("New line is optional but recommended\n\n");
	printf ("\tPart 2: The colors\n\n");
	printf ("F 220,100,0\n");
	printf ("C 255,255,255\n");
	printf ("New line is optional but recommended\n\n");
	printf ("\tPart 3: The map\n\n");
	printf ("111111\n");
	printf ("100001\n");
	printf ("100001\n");
	printf ("111111\n");
}

/*	================================================================	*/