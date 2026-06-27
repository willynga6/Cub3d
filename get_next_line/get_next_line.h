/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:24:31 by wngambi           #+#    #+#             */
/*   Updated: 2026/06/27 17:53:53 by wngambi          ###   ########.fr       */
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
# include <structure.h>

/* Forward declaration to avoid circular includes */

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