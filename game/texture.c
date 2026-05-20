/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:12:47 by otidahoh          #+#    #+#             */
/*   Updated: 2026/05/20 15:29:06 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <string.h>

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		len;
	char	*res;
	int		i;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = strlen(s1) - 1;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end >= start && is_in_set(s1[end], set))
		end--;
	len = end - start + 1;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s1[start + i];
	res[i] = '\0';
	return (res);
}

int	load_texture(t_game *game, t_texture *tex, char *path)
{
	if (!game || !tex || !path)
		return (0);
	tex->img = mlx_xpm_file_to_image(game->mlx.mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
	{
		printf("Error: failed to load texture: %s\n", path);
		return (0);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (!tex->addr)
	{
		printf("Error: failed to get texture data: %s\n", path);
		return (0);
	}
	return (1);
}

int	load_all_textures(t_game *game)
{
	if (!load_texture(game, &game->no, game->parsing.no_texture))
		return (0);
	if (!load_texture(game, &game->so, game->parsing.so_texture))
		return (0);
	if (!load_texture(game, &game->we, game->parsing.we_texture))
		return (0);
	if (!load_texture(game, &game->ea, game->parsing.ea_texture))
		return (0);
	return (1);
}
