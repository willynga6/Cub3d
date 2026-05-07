/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_mapfile_format                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 08:42:11 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/07 09:40:26 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

/*	================================================================	*/

bool    in_nothing_part(t_parsing *s_parsing)
{
    if (s_parsing->am_i_in_map)
        return (false);
    if (s_parsing->am_i_in_color)
        return (false);
    if (s_parsing->am_i_in_texture)
        return (false);
    return (true);
}

/*	================================================================	*/

