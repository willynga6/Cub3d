/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:24:31 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/12 17:34:27 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* Forward declaration to avoid circular includes */
typedef struct s_malloc
{
	struct s_malloc	*next;
	void			*adr_malloc;
}					t_malloc;

void	*malloc_remix(t_malloc **lst_malloc, size_t nb_octets);

char	*ft_strjoin(t_malloc **lst_malloc, char *s1, char *s2);
char	*ft_strdup(t_malloc **lst_malloc, char *s);
char	*ft_strndup(t_malloc **lst_malloc, char *s, int size);
char	*ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*get_next_line(t_malloc **lst_malloc, int fd);
char	*extract_line(t_malloc **lst_malloc, char *stash);
char	*clean_update_stash(t_malloc **lst_malloc, char *stash);

#endif