/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:37:02 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/20 14:54:37 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*	================================================================	*/

# include <stdbool.h>

# define FIRST_LINE_ERROR "Err: 1st line must only composed of '1' and spaces"
# define LAST_LINE_ERROR "Error: Last line must only composed of '1' and spaces"

/*	================================================================	*/

typedef struct s_map		t_map;
typedef struct s_malloc		t_malloc;
typedef struct s_player		t_player;
typedef struct s_parsing	t_parsing;

/*	================================================================	*/

struct						s_map
{
	char					**map;
	int						nb_lines;
	int						max_line_length;
};

/*	================================================================	*/

struct						s_player
{
	int						map_x;
	int						map_y;
	double					pos_x;
	double					pos_y;
	double					plane_x;
	double					plane_y;
	double					dir_x;
	double					dir_y;
	int						move_up;
	int						move_down;
	int						move_left;
	int						move_right;
	int						rotate_left;
	int						rotate_right;

	char					**flood_f_map;
};

/*	================================================================	*/

struct						s_parsing
{
	int						ac;
	char					*maps_path;
	char					**maps;
	t_map					final_maps;
	t_malloc				**lst_malloc;
	char					*no_texture;
	char					*so_texture;
	char					*we_texture;
	char					*ea_texture;
	int						fd_map;
	char					*f_color;
	char					*c_color;
	int						nb_lines;
	bool					contain_no_texture;
	bool					contain_so_texture;
	bool					contain_we_texture;
	bool					contain_ea_texture;
	bool					am_i_in_map;
	bool					contain_f_color;
	bool					contain_c_color;
	bool					am_i_in_color;
	bool					am_i_in_texture;
	t_player				player;
};

/*	================================================================	*/

/*struct s_malloc
{
	struct s_malloc	*next;
	void			*adr_malloc;
};*/

/*	================================================================	*/

typedef struct s_mlx
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
}							t_mlx;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_game
{
	double					last_time;
	t_texture				no;
	t_texture				so;
	t_texture				ea;
	t_texture				we;
	t_texture				floor;
	t_texture				ceiling;
	t_parsing				parsing;
	int						prev_ms_x;
	t_mlx					mlx;
}							t_game;

#endif