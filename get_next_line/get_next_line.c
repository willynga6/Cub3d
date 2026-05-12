/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:38:24 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/08 10:00:11 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(t_malloc **lst_malloc, char *stash)
{
	char	*line;
	char	*nl;

	if (!stash)
		return (NULL);
	nl = ft_strchr(stash, '\n');
	if (!nl)
	{
		line = ft_strdup(lst_malloc, stash);
		return (line);
	}
	else
	{
		line = ft_strndup(lst_malloc, stash, (nl - stash + 1));
		return (line);
	}
}

char	*clean_update_stash(t_malloc **lst_malloc, char *stash)
{
	char	*new_stash;
	char	*new_line;

	if (!stash)
		return (NULL);
	new_line = ft_strchr(stash, '\n');
	if (!new_line)
		return (NULL);
	if (*(new_line + 1) == '\0')
		return (NULL);
	new_stash = ft_strdup(lst_malloc, new_line + 1);
	return (new_stash);
}

/*=============================================================*/

char	*get_next_line(t_malloc **lst_malloc, int fd)
{
	static char	*stash;
	char		*buffer;
	int			lecture;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || !lst_malloc)
		return (NULL);
	buffer = malloc_remix(lst_malloc, sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (lecture == -1)
			return (NULL);
		buffer[lecture] = '\0';
		if (lecture == 0)
			break ;
		stash = ft_strjoin(lst_malloc, stash, buffer);
	}
	line = extract_line(lst_malloc, stash);
	stash = clean_update_stash(lst_malloc, stash);
	return (line);
}

/*
int	main(void)
{
	int			fd;
	char		*lecture;

	fd = open("txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erreur ouverture fichier\n");
		return (-1);
	}
	lecture = "go";
	while (lecture)
	{
		lecture = get_next_line(fd);
		printf("%s", lecture);
		free(lecture);
	}
	return (0);
}
*/