/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:53:06 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/26 18:09:57 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

/*	================================================================	*/

bool	is_digit_char(char c)
{
	return (c >= '0' && c <= '9');
}

/*	================================================================	*/

bool	is_valid_rgb_component(char *component)
{
	int	i;
	int	value;

	if (!component)
		return (false);
	i = 0;
	while (component[i] && is_space(component[i]))
		i++;
	if (!component[i])
		return (false);
	value = 0;
	while (component[i] && is_digit_char(component[i]))
	{
		value = (value * 10) + (component[i] - '0');
		if (value > 255)
			return (false);
		i++;
	}
	while (component[i] && is_space(component[i]))
		i++;
	if (component[i] != '\0')
		return (false);
	return (true);
}

/*	================================================================	*/

bool	is_valid_rgb_value(t_parsing *parsing, char *value)
{
	char	**rgb_values;

	rgb_values = ft_split(parsing->lst_malloc, value, ',');
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2]
		|| rgb_values[3])
		return (false);
	if (!is_valid_rgb_component(rgb_values[0]))
		return (false);
	if (!is_valid_rgb_component(rgb_values[1]))
		return (false);
	if (!is_valid_rgb_component(rgb_values[2]))
		return (false);
	return (true);
}

/*	================================================================	*/

bool	save_color_value(t_parsing *parsing, char *line, bool is_f)
{
	char	**value;

	value = ft_split(parsing->lst_malloc, line, ' ');
	if (!value || !value[0] || !value[1] || value[2])
		return (false);
	if (!is_valid_rgb_value(parsing, value[1]))
		return (false);
	if (is_f)
		parsing->f_color = value[1];
	else
		parsing->c_color = value[1];
	return (true);
}

/*	================================================================	*/

bool	is_f_color_part(char *line)
{
	if (!line)
		return (false);
	if (line[0] == 'F' && is_space(line[1]))
		return (true);
	return (false);
}

/*	================================================================	*/
