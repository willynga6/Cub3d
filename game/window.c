/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:54:13 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 13:29:21 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	=====================================================================	*/

bool	init_mlx(t_game *game)
{
	if (!game)
		return (false);
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (false);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_WIDTH, WIN_HEIGHT,
			"Cub3D");
	if (!game->mlx.win)
		return (false);
	mlx_mouse_hide(game->mlx.mlx, game->mlx.win);//
	return (true);
}

/*	=====================================================================	*/

void	init_image(t_game *game)
{
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bits_per_pixel,
			&game->mlx.line_length, &game->mlx.endian);
}

/*	=====================================================================	*/

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

/*	=====================================================================	*/

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = game->mlx.addr + (y * game->mlx.line_length + x
			* (game->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*	=====================================================================	*/

void	display_image(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}
