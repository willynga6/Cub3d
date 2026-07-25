/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:03:05 by wngambi           #+#    #+#             */
/*   Updated: 2026/07/24 16:52:47 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"

void	free_lst_malloc(t_malloc **lst_malloc)
{
	t_malloc	*tmp;

	if (!lst_malloc)
		return ;
	while (*lst_malloc)
	{
		tmp = (*lst_malloc)->next;
		free((*lst_malloc)->adr_malloc);
		free(*lst_malloc);
		*lst_malloc = tmp;
	}
}

void	free_texture_paths(t_game *game)
{
	free(game->parsing.no_texture);
	free(game->parsing.so_texture);
	free(game->parsing.we_texture);
	free(game->parsing.ea_texture);
	game->parsing.no_texture = NULL;
	game->parsing.so_texture = NULL;
	game->parsing.we_texture = NULL;
	game->parsing.ea_texture = NULL;
}

void	destroy_texture(t_game *game, t_texture *tex)
{
	if (!game || !game->mlx.mlx || !tex || !tex->img)
		return ;
	mlx_destroy_image(game->mlx.mlx, tex->img);
	tex->img = NULL;
	tex->addr = NULL;
}

void	destroy_gun_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
		destroy_texture(game, &game->gun.frame_idle[i++]);
	i = 0;
	while (i < 3)
		destroy_texture(game, &game->gun.frame_shoot[i++]);
	i = 0;
	while (i < 5)
		destroy_texture(game, &game->gun.frame_reload[i++]);
}

void	destroy_all_textures(t_game *game)
{
	destroy_texture(game, &game->no);
	destroy_texture(game, &game->so);
	destroy_texture(game, &game->we);
	destroy_texture(game, &game->ea);
	destroy_texture(game, &game->floor);
	destroy_texture(game, &game->ceiling);
	destroy_texture(game, &game->door.door_frame[0]);
	destroy_texture(game, &game->door.door_frame[1]);
	destroy_gun_textures(game);
}
