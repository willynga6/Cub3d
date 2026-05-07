/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:37:02 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/07 08:49:24 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "cub3D.h"

/*	================================================================	*/

typedef struct s_parsing
{
	int		ac;
	char	*maps_path;
	int		fd_map;
	bool	contain_no_texture;
	bool	contain_so_texture;
	bool	contain_we_texture;
	bool	contain_ea_texture;
	bool	am_i_in_map;
	bool	am_i_in_color;
	bool	am_i_in_texture;

}	t_parsing;

/*	================================================================	*/

typedef struct s_malloc
{
	struct s_malloc	*next;
	void			*adr_malloc;
}	t_malloc;

/*	================================================================	*/

#endif