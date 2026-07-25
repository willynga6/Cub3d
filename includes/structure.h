/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:37:02 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 17:56:11 by wngambi          ###   ########.fr       */
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

struct s_malloc
{
	struct s_malloc	*next;
	void			*adr_malloc;
};

/*	================================================================	*/

struct						s_map
{
	char					**map;
	int						nb_lines;
	int						max_line_length;
	int						**door_open;
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

typedef struct s_draw_line
{
	int		x;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_draw_line;

/*	================================================================	*/

typedef struct s_raycasting
{
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			x;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			door_found;
	int			door_x;
	int			door_y;
	int			door_side;
	double		perp_wall_dist;
	double		door_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	char		tile;
}	t_raycasting;

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

/*	================================================================	*/

typedef struct s_gun
{
	t_texture	frame_idle[5];
	t_texture	frame_shoot[3];
	t_texture	frame_reload[5];

	int			current_frame;
	double		animation_timer;
	bool		is_shooting;
	int			ammunition;
	int			is_reloading;
	int			gun_x;
	int			gun_y;
}	t_gun;

/*	================================================================	*/

typedef struct s_door
{
	int			**door_open;
	int			nb_lines;
	int			max_line_length;
	t_texture	door_frame[2];

}	t_door;

/*	================================================================	*/

typedef struct s_game_loop
{
	double		current;
	double		dt;
	double		move_speed;
	double		rot_speed;
	double		new_x;
	double		new_y;
	t_player	*player;
}	t_game_loop;

/*	================================================================	*/

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
	t_gun					gun;
	t_door					door;
	t_game_loop				game_loop;
	t_raycasting			ray;
	t_malloc				*lst_malloc;
}							t_game;

#endif