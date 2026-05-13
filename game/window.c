/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:42:08 by otidahoh          #+#    #+#             */
/*   Updated: 2026/05/13 15:10:18 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (false);
	game->mlx.win = mlx_new_window(game->mlx.mlx, 800, 600, "cub3d");
	if (!game->mlx.win)
		return (false);
	return (true);
}
void	init_image(t_game *game)
{
	game->mlx.img = mlx_new_image(game->mlx.mlx, 800, 600);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bits_per_pixel,
			&game->mlx.line_length, &game->mlx.endian);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 800 || y >= 600)
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

void	draw_player(t_game *game)
{
	int	px;
	int	py;
	int	i;
	int	j;

	 px = (int)(game->parsing.player.pos_x * TILE_SIZE);
    py = (int)(game->parsing.player.pos_y * TILE_SIZE);
	i = -2;
	while (i < 3)
	{
		j = -2;
		while (j < 3)
		{
			put_pixel(game, px + i, py + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (game->parsing.final_maps.map[y])
	{
		x = 0;
		while (game->parsing.final_maps.map[y][x])
		{
			if (game->parsing.final_maps.map[y][x] == '1')
				color = 0x222222; // wall (dark gray)
			else
				color = 0xCCCCCC; // floor (light gray)
			draw_square(game, x, y, color);
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
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			put_pixel(game, x, y, 0x000000);
			x++;
		}
		y++;
	}
	draw_map(game);
	draw_player(game);
	display_image(game);
	return (0);
}
