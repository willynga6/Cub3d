/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:42:08 by otidahoh          #+#    #+#             */
/*   Updated: 2026/05/21 12:49:01 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (false);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_WIDTH, WIN_HEIGHT,
			"cub3d");
	if (!game->mlx.win)
		return (false);
	mlx_mouse_hide(game->mlx.mlx, game->mlx.win);
	return (true);
}

void	init_image(t_game *game)
{
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bits_per_pixel,
			&game->mlx.line_length, &game->mlx.endian);
}

int	get_texture_pixel(t_texture *tex, int x, int y)
{
	char	*dst;

	if (!tex || !tex->addr)
		return (0);
	if (x < 0 || y < 0 || x >= tex->width || y >= tex->height)
		return (0);
	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = game->mlx.addr + (y * game->mlx.line_length + x
			* (game->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	display_image(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}

void	extract_player(t_parsing *p)
{
	int	x;
	int	y;

	p->player.move_up = 0;
	p->player.move_down = 0;
	p->player.move_left = 0;
	p->player.move_right = 0;
	p->player.rotate_left = 0;
	p->player.rotate_right = 0;
	y = 0;
	while (p->final_maps.map[y])
	{
		x = 0;
		while (p->final_maps.map[y][x])
		{
			if (p->final_maps.map[y][x] == 'N' || p->final_maps.map[y][x] == 'S'
				|| p->final_maps.map[y][x] == 'E'
				|| p->final_maps.map[y][x] == 'W')
			{
				init_player_dir(&p->player, p->final_maps.map[y][x]);
				p->player.pos_x = x + 0.5;
				p->player.pos_y = y + 0.5;
				p->player.map_x = x;
				p->player.map_y = y;
				p->final_maps.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	draw_square(t_game *game, int map_x, int map_y, int color)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = map_x * TILE_SIZE;
	start_y = map_y * TILE_SIZE;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			put_pixel(game, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_ceiling_and_floor(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel(game, x, y, 0x3B2F2F);
			else
				put_pixel(game, x, y, 0x5C4033);
			x++;
		}
		y++;
	}
}

int	render_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(game, x, y, 0x000000);
			x++;
		}
		y++;
	}
	draw_ceiling_and_floor(game);
	cast_ray(game);
	draw_minimap(game);
	draw_minimap_player(game);
	draw_minimap_dir(game);
	draw_cross_s(game);
	display_image(game);
	return (0);
}
