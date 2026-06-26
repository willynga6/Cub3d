/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:50:32 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 20:41:22 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

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

void	display_final_map(const t_map *final_map)
{
	int	i;

	if (!final_map || !final_map->map)
	{
		printf("Final map is NULL or empty\n");
		return ;
	}
	printf("\n========== FINAL MAP ==========\n");
	printf("Number of lines: %d\n", final_map->nb_lines);
	printf("Max line length: %d\n", final_map->max_line_length);
	printf("Map content:\n");
	printf("------------------------------\n");
	i = 0;
	while (final_map->map[i])
	{
		printf("%s\n", final_map->map[i]);
		i++;
	}
	printf("------------------------------\n");
}

/*	================================================================	*/

char	**duplicate_maps(t_parsing *parsing, t_malloc **lst_malloc)
{
	char	**original_maps;
	char	**maps_copy;
	int		i;

	if (!parsing || !parsing->final_maps.map)
		return (NULL);
	original_maps = parsing->final_maps.map;
	maps_copy = malloc_remix(lst_malloc,
			sizeof(char *) * (parsing->final_maps.nb_lines + 1));
	if (!maps_copy)
		return (NULL);
	i = 0;
	while (i < parsing->nb_lines)
	{
		maps_copy[i] = ft_strdup(lst_malloc, original_maps[i]);
		i++;
	}
	maps_copy[i] = NULL;
	return (maps_copy);
}

/*	================================================================	*/
