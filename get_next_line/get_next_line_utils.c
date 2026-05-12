/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:28:38 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/10 10:26:15 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

/*=============================================================*/

char	*ft_strdup(t_malloc **lst_malloc, char *s)
{
	int		i;
	char	*copy;

	if (!s || !lst_malloc)
		return (NULL);
	if (!*s)
	{
		copy = malloc_remix(lst_malloc, 1);
		if (!copy)
			return (NULL);
		copy[0] = '\0';
		return (copy);
	}
	i = 0;
	copy = malloc_remix(lst_malloc, sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*=============================================================*/

char	*ft_strndup(t_malloc **lst_malloc, char *s, int size)
{
	char	*copy;
	int		len;

	if (!s || size < 0 || !lst_malloc)
		return (NULL);
	if (!*s || size == 0)
	{
		copy = malloc_remix(lst_malloc, 1);
		if (!copy)
			return (NULL);
		return (copy[0] = '\0', copy);
	}
	len = ft_strlen(s);
	copy = malloc_remix(lst_malloc, sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	if (size > len)
		size = len;
	len = -1;
	while (++len < size)
		copy[len] = s[len];
	return (copy[len] = '\0', copy);
}

/*=============================================================*/

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

/*=============================================================*/

char	*ft_strjoin(t_malloc **lst_malloc, char *s1, char *s2)
{
	char	*copy;
	int		i;
	int		j;

	if (!lst_malloc)
		return (NULL);
	if (!s1)
		s1 = ft_strdup(lst_malloc, "");
	if (!s1)
		return (NULL);
	if (!s2)
		return (s1);
	copy = malloc_remix(lst_malloc, sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (s1[++i])
		copy[i] = s1[i];
	j = 0;
	while (s2[j])
		copy[i++] = s2[j++];
	return (copy[i] = '\0', copy);
}
