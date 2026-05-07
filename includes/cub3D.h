/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:34:54 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/07 09:17:41 by wngambi          ###   ########.fr       */
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

bool	ft_charcmp(const char c1, const char c2);
void	display_parsing(const t_parsing *parsing);

/*  PARSING */

bool	init_parsing(char **av, int ac, t_parsing *parsing);
bool	is_valid_extension(t_parsing *parsing);

/*   CLEAN  */
bool	init_lst_malloc(t_malloc **lst_malloc);
void	*malloc_remix(t_malloc **lst_malloc, size_t nb_octets);
void	free_lst_malloc(t_malloc **lst_malloc);

#endif
