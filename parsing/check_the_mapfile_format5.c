/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_mapfile_format5.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 08:40:08 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/10 10:13:25 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

/*	================================================================	*/

static bool	is_digit_char(char c)
{
	return (c >= '0' && c <= '9');
}

/*	================================================================	*/

static bool	is_valid_rgb_component(char *component)
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

static bool	is_valid_rgb_value(t_parsing *parsing, char *value)
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

static bool	save_color_value(t_parsing *parsing, char *line, bool is_f)
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

bool	is_c_color_part(char *line)
{
	if (!line)
		return (false);
	if (line[0] == 'C' && is_space(line[1]))
		return (true);
	return (false);
}

/*	================================================================	*/

bool	all_color_part_is_here(t_parsing *parsing)
{
	if (!parsing)
		return (false);
	if (mute_all_color_part_is_here(parsing))
		return (true);
	if (!parsing->contain_f_color)
		print_error("Error: F color is missing");
	if (!parsing->contain_c_color)
		print_error("Error: C color is missing");
	return (false);
}

/*	================================================================	*/

bool	mute_all_color_part_is_here(t_parsing *parsing)
{
	if (!parsing)
		return (false);
	if (!parsing->contain_f_color)
		return (false);
	if (!parsing->contain_c_color)
		return (false);
	return (true);
}

/*	================================================================	*/

bool	am_i_in_color_part(t_parsing *parsing, int *i)
{
	if (!parsing || !i || !parsing->maps || !parsing->maps[*i])
		return (false);
	if (is_f_color_part(parsing->maps[*i]) || is_c_color_part(parsing->maps[*i]))
	{
		parsing->am_i_in_color = true;
		return (true);
	}
	if (all_color_part_is_here(parsing))
	{
		parsing->am_i_in_color = false;
		return (true);
	}
	return (false);
}

/*	================================================================	*/

bool	mute_am_i_in_color_part(t_parsing *parsing, int *i)
{
	if (!parsing || !i || !parsing->maps || !parsing->maps[*i])
		return (false);
	if (is_f_color_part(parsing->maps[*i]) || is_c_color_part(parsing->maps[*i]))
	{
		parsing->am_i_in_color = true;
		return (true);
	}
	if (mute_all_color_part_is_here(parsing))
	{
		parsing->am_i_in_color = false;
		return (true);
	}
	return (false);
}

/*	================================================================	*/

bool	color_case(t_parsing *parsing, int *i)
{
	if (!parsing || !i)
		return (false);
	while (parsing->maps[*i]
		&& (is_f_color_part(parsing->maps[*i])
			|| is_c_color_part(parsing->maps[*i])))
	{
		if (is_f_color_part(parsing->maps[*i]))
		{
			if (parsing->contain_f_color)
				return (print_error("Error: double F color"), false);
			if (!save_color_value(parsing, parsing->maps[*i], true))
				return (print_error("Error: invalid F color format"), false);
			parsing->contain_f_color = true;
		}
		else if (is_c_color_part(parsing->maps[*i]))
		{
			if (parsing->contain_c_color)
				return (print_error("Error: double C color"), false);
			if (!save_color_value(parsing, parsing->maps[*i], false))
				return (print_error("Error: invalid C color format"), false);
			parsing->contain_c_color = true;
		}
		else
			return (false);
		(*i)++;
	}
	if (!all_color_part_is_here(parsing))
		return (false);
	return (true);
}

/*	================================================================	*/

static bool	is_map_line(char *line, int *player_count)
{
	int	j;

	if (!line)
		return (false);
	j = 0;
	while (line[j])
	{
		if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E' || line[j] == 'W')
			(*player_count)++;
		if (line[j] == '0' || line[j] == '1' || line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'W' || is_space(line[j]))
		{
			j++;
			continue ;
		}
		return (false);
	}
	return (true);
}

/*	================================================================	*/

bool	map_case(t_parsing *parsing, int *i)
{
	int	player_count;
	int	map_start;

	if (!parsing || !i || !parsing->maps || !parsing->maps[*i])
		return (print_error("Error: map is missing"), false);
	player_count = 0;
	map_start = *i;
	parsing->am_i_in_map = true;
	while (parsing->maps[*i] && !is_empty_line(parsing->maps[*i]))
	{
		if (!is_map_line(parsing->maps[*i], &player_count))
			return (print_error("Error: invalid map character"), false);
		(*i)++;
	}
	jump_empty_line(parsing, i);
	if (parsing->maps[*i])
		return (print_error("Error: invalid content after map"), false);
	if (player_count != 1)
		return (print_error("Error: map must contain exactly one player"), false);
	parsing->maps = &parsing->maps[map_start];
	return (true);
}