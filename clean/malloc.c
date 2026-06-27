/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:49:29 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 18:03:51 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h"
#include "get_next_line.h"

bool	init_lst_malloc(t_malloc **lst_malloc)
{
	if (!lst_malloc)
		return (false);
	*lst_malloc = malloc(sizeof(t_malloc));
	if (!*lst_malloc)
		return (perror ("Malloc lst_malloc:"), false);
	(*lst_malloc)->next = NULL;
	(*lst_malloc)->adr_malloc = NULL;
	return (true);
}

/*	================================================================	*/

static bool	add_back_malloc(t_malloc **lst_malloc, void *adr_malloc)
{
	t_malloc	*new_node;
	t_malloc	*last_node;

	if (!lst_malloc || !adr_malloc)
		return (false);
	new_node = malloc(sizeof(t_malloc));
	if (!new_node)
		return (perror("Malloc new_node:"), false);
	new_node->adr_malloc = adr_malloc;
	new_node->next = NULL;
	if (!*lst_malloc)
	{
		*lst_malloc = new_node;
		return (true);
	}
	last_node = *lst_malloc;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	return (true);
}

/*	================================================================	*/

void	*malloc_remix(t_malloc **lst_malloc, size_t nb_octets)
{
	void	*adress_data;

	if (!lst_malloc)
		return (NULL);
	adress_data = malloc(nb_octets);
	if (!adress_data)
		return (NULL);
	if (!add_back_malloc(lst_malloc, adress_data))
	{
		free(adress_data);
		return (NULL);
	}
	return (adress_data);
}

/*	================================================================	*/

void	clean_and_close(t_malloc **lst_malloc, int fd)
{
	if (lst_malloc)
		free_lst_malloc(lst_malloc);
	if (fd >= 0)
		close(fd);
}
