/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 06:34:54 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 17:52:59 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*  ====================ALL THE LIBRAIRIES USED ====================*/

# include <mlx.h>
# include "structure.h"
# include <fcntl.h> // open
# include <math.h>
# include <stdbool.h> // To get the boolean value.
# include <stdio.h>   // printf
# include <stdlib.h>  // malloc / free / perror / exit
# include <unistd.h>  // close / read / write
# define TILE_SIZE 32
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MM_SCALE 8
# define MM_OFFSET_X 10
# define MM_OFFSET_Y 10
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define NO_TEX "textures/wall_no.xpm"
# define SO_TEX "textures/wall_so.xpm"
# define WE_TEX "textures/wall_we.xpm"
# define EA_TEX "textures/wall_ea.xpm"
# define F_TEX "textures/floor_cub.xpm"
# define C_TEX "textures/ceiling.xpm"
/*  ====================ALL THE FUNCTION USED ====================*/

/*  PARSING */
bool		parsing(t_game *game, char **av, int ac, t_malloc **lst_malloc);

/*  CHECK INIT PARSING */
bool		init_parsing(char **av, int ac, t_parsing *parsing,
				t_malloc **lst_malloc);
int			count_lines(char *filename, t_malloc **lst_malloc);
char		**get_maps(t_parsing *parsing, t_malloc **lst_malloc);

/*  CHECK EXTENSION */
bool		is_valid_extension(t_parsing *parsing);
bool		check_extension(char *str);

/*  CHECK THE FILE FORMAT */

/*	format 1*/
bool		in_nothing_part(t_parsing *parsing);
bool		is_empty_file(t_parsing *parsing);
void		jump_empty_line(t_parsing *parsing, int *i);
bool		am_i_in_texture_part(t_parsing *parsing, int *i);
bool		check_the_mapfile_format(t_parsing *parsing);

/*	format 2*/
bool		is_no_texture_part(char *line);
bool		is_so_texture_part(char *line);
bool		is_we_texture_part(char *line);
bool		is_ea_texture_part(char *line);
bool		all_texture_part_is_here(t_parsing *parsing);

/*	format 2bis*/
bool		mute_all_texture_part_is_here(t_parsing *parsing);

/*	format 3*/
bool		double_no_texture(t_parsing *parsing, char *line);
bool		double_so_texture(t_parsing *parsing, char *line);
bool		double_we_texture(t_parsing *parsing, char *line);
bool		double_ea_texture(t_parsing *parsing, char *line);

/*	format 4*/
bool		no_case(t_parsing *parsing, char *line, int *i);
bool		so_case(t_parsing *parsing, char *line, int *i);
bool		we_case(t_parsing *parsing, char *line, int *i);
bool		ea_case(t_parsing *parsing, char *line, int *i);
bool		texture_case(t_parsing *parsing, int *i);

/*	format 5*/
bool		is_digit_char(char c);
bool		is_valid_rgb_component(char *component);
bool		is_valid_rgb_value(t_parsing *parsing, char *value);
bool		save_color_value(t_parsing *parsing, char *line, bool is_f);
bool		is_f_color_part(char *line);

/*	format 6*/
bool		is_c_color_part(char *line);
bool		all_color_part_is_here(t_parsing *parsing);
bool		mute_all_color_part_is_here(t_parsing *parsing);
bool		am_i_in_color_part(t_parsing *parsing, int *i);
bool		mute_am_i_in_color_part(t_parsing *parsing, int *i);

/*	format 7*/
bool		color_case(t_parsing *parsing, int *i);
bool		map_case(t_parsing *parsing, int *i);

/*	format 8*/
bool		convert_new_line_into_eol(t_parsing *parsing);

/*  CHECK THE MAP */

/*	FILE 1*/
int			get_number_of_lines(t_parsing *parsing);
int			get_max_line_length(t_parsing *parsing);
bool		only_walls(t_parsing *parsing);
bool		init_map(t_parsing *parsing);

/*	FILE 2*/
bool		check_first_and_last_line(t_parsing *parsing, int nb_lines);
bool		only_one_player(t_parsing *parsing);
bool		quick_check_map_format(t_parsing *parsing);
bool		check_map_format(t_parsing *parsing);

/*	FILE 3*/
bool		maj_position_player(t_parsing *parsing);
void		replace_pos_by_zero(t_parsing *parsing);
bool		set_up_flood_fill(t_parsing *parsing, t_malloc **lst_malloc);
void		real_flood_fill(t_parsing *p, int y, int x, bool *res);
bool		flood_fill(t_parsing *parsing, t_malloc **lst_malloc);

/*	INIT PLAYER */

	/*	FILE 1*/
void		init_player_int_double_value(t_player *player);
void		extract_player(t_parsing *p);

	/*	FILE 2*/
void		init_player_dir(t_player *p, char c);

/*   CLEAN  */
bool		init_lst_malloc(t_malloc **lst_malloc);
void		*malloc_remix(t_malloc **lst_malloc, size_t nb_octets);
void		free_lst_malloc(t_malloc **lst_malloc);

/*      TOOLS   */
bool		ft_charcmp(const char c1, const char c2);
void		display_parsing(const t_parsing *parsing);
char		**ft_split(t_malloc **lst_malloc, char *s, char c);
void		display_maps(char **maps);
void		display_final_map(const t_map *final_map);
char		**duplicate_maps(t_parsing *parsing, t_malloc **lst_malloc);
bool		is_space(char c);
bool		is_empty_line(char *line);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(t_malloc **lst_malloc, char *s);
void		print_error(const char *message);
void		required_format(void);
void		clean_and_close(t_malloc **lst_malloc, int fd);
int			ft_strlen(char *s);

/*		RAYCASTING	*/
void		init_ray(t_game *game);
void		init_dda(t_game *game);
void		move_ray_one_step(t_raycasting *r);
void		check_ray_tile(t_game *game);
int			is_ray_outside_map(t_game *game);
void		perform_dda(t_game *game);
void		compute_wall_projection(t_game *game);
void		compute_tex_x(t_game *game, t_texture *tex);
t_texture	*select_texture(t_game *game, int side, double ray_dir_x,
				double ray_dir_y);
void		draw_texture_line(t_game *game, t_texture *tex, t_draw_line *d);
void		draw_texture_line_trans(t_game *game, t_texture *tex,
				t_draw_line *d);
t_texture	*get_hit_texture(t_game *game);
void		draw_wall_hit(t_game *game);
void		compute_open_door_projection(t_game *game);
void		compute_open_door_tex_x(t_game *game, t_texture *tex);
void		draw_open_door_if_needed(t_game *game);

bool		init_mlx(t_game *game);
void		init_image(t_game *game);
void		put_pixel(t_game *game, int x, int y, int color);
void		display_image(t_game *game);
int			render_frame(t_game *game);
int			render_frame_bonus(t_game *game);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
double		get_time(void);
int			game_loop(t_game *game);
int			game_loop_bonus(t_game *game);
void		game_loop_init(t_game *game);
int			is_wall(t_parsing *p, double x, double y);
int			close_window(t_game *game);
void		rotate_p(t_player *p, double rot_spd);
void		cast_ray(t_game *game);
void		draw_square(t_game *game, int map_x, int map_y, int color);
void		draw_ceiling_and_floor(t_game *game);
void		draw_minimap_dir(t_game *game);
void		draw_minimap_player(t_game *game);
void		draw_minimap(t_game *game);
int			load_all_textures(t_game *game);
int			load_texture(t_game *game, t_texture *tex, char *path);
int			load_gun(t_game *game);
int			get_texture_pixel(t_texture *tex, int x, int y);
char		*ft_strtrim(const char *s1, const char *set);
int			mouse_move(int x, int y, t_game *game);
void		draw_cross_s(t_game *game);
void		toggle_door(t_game *game);
bool		init_doors(t_parsing *parsing);
bool		is_player_char(char c);

/*	CLEAN	*/
void		free_lst_malloc(t_malloc **lst_malloc);
void		clean_mlx_and_malloc_lst(t_game *game, t_malloc **lst_malloc);

/*	BONUS 	*/

	/*	GUN.C*/
void		init_gun(t_game *game);
void		update_gun(t_game *game, double dt);

	/*	MOUSS-EVENT.C*/

int			mouse_press(int button, int x, int y, t_game *game);
void		draw_gun(t_game *game);
void		render_gun(t_game *game);

	/*	PARSING_BONUS.c	*/
bool		parsing_bonus(t_game *game, char **av,
				int ac, t_malloc **lst_malloc);

#endif
