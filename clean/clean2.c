/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:04:11 by wngambi           #+#    #+#             */
/*   Updated: 2026/07/24 16:04:36 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

void	clean_mlx_and_malloc_lst(t_game *game, t_malloc **lst_malloc)
{
	if (!game)
		return ;
	if (game->parsing.fd_map >= 0)
	{
		close(game->parsing.fd_map);
		game->parsing.fd_map = -1;
	}
	destroy_all_textures(game);
	if (game->mlx.img)
	{
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
		game->mlx.img = NULL;
	}
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
	{
		mlx_destroy_display(game->mlx.mlx);
		free(game->mlx.mlx);
		game->mlx.mlx = NULL;
	}
	free_texture_paths(game);
	free_lst_malloc(lst_malloc);
}
