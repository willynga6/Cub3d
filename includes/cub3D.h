/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:34:54 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/10 10:06:09 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*  ====================ALL THE LIBRAIRIES USED ====================*/

# include <stdbool.h> // To get the boolean value.
# include <fcntl.h> // open
# include <unistd.h> // close / read / write
# include <stdio.h> // printf
# include <stdlib.h> // malloc / free / perror / exit
# include "structure.h"

/*  ====================ALL THE FUNCTION USED ====================*/

/*  PARSING */

	/*  CHECK INIT PARSING */
bool	init_parsing(char **av, int ac, t_parsing *parsing,
			t_malloc **lst_malloc);
int		count_lines(char *filename, t_malloc **lst_malloc);
char	**get_maps(t_parsing *parsing, t_malloc **lst_malloc);

	/*  CHECK EXTENSION */
bool	is_valid_extension(t_parsing *parsing);

	/*  CHECK THE MAP FILE FORMAT */
		/*	format 1*/
bool	in_nothing_part(t_parsing *parsing);
bool	is_empty_file(t_parsing *parsing);
void	jump_empty_line(t_parsing *parsing, int *i);
bool	am_i_in_texture_part(t_parsing *parsing, int *i);
bool	mute_am_i_in_texture_part(t_parsing *parsing, int *i);
bool	check_the_mapfile_format(t_parsing *parsing);
		/*	format 2*/
bool	is_no_texture_part(char *line);
bool	is_so_texture_part(char *line);
bool	is_we_texture_part(char *line);
bool	is_ea_texture_part(char *line);
bool	all_texture_part_is_here(t_parsing *parsing);
bool	mute_all_texture_part_is_here(t_parsing *parsing);

		/*	format 5*/
bool	is_f_color_part(char *line);
bool	is_c_color_part(char *line);
bool	am_i_in_color_part(t_parsing *parsing, int *i);
bool	mute_am_i_in_color_part(t_parsing *parsing, int *i);
bool	all_color_part_is_here(t_parsing *parsing);
bool	mute_all_color_part_is_here(t_parsing *parsing);
bool	color_case(t_parsing *parsing, int *i);
bool	map_case(t_parsing *parsing, int *i);

		/*	format 3*/
bool	double_no_texture(t_parsing *parsing, char *line);
bool	double_so_texture(t_parsing *parsing, char *line);
bool	double_we_texture(t_parsing *parsing, char *line);
bool	double_ea_texture(t_parsing *parsing, char *line);
		/*	format 4*/
bool	no_case(t_parsing *parsing, char *line, int *i);
bool	so_case(t_parsing *parsing, char *line, int *i);
bool	we_case(t_parsing *parsing, char *line, int *i);
bool	ea_case(t_parsing *parsing, char *line, int *i);
bool	texture_case(t_parsing *parsing, int *i);

/*   CLEAN  */
bool	init_lst_malloc(t_malloc **lst_malloc);
void	*malloc_remix(t_malloc **lst_malloc, size_t nb_octets);
void	free_lst_malloc(t_malloc **lst_malloc);

/*      TOOLS   */
bool	ft_charcmp(const char c1, const char c2);
void	display_parsing(const t_parsing *parsing);
char	**ft_split(t_malloc **lst_malloc, char *s, char c);
void	display_maps(char **maps);
bool	is_space(char c);
bool	is_empty_line(char *line);
int		ft_strcmp(const char *s1, const char *s2);
void	print_error(const char *message);
void	required_format(void);

#endif
