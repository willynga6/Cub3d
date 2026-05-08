/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:12:10 by wngambi           #+#    #+#             */
/*   Updated: 2026/05/08 12:41:42 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "structure.h" 

/*	================================================================	*/

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

/*	================================================================	*/

static char	*word_dup(t_malloc **lst_malloc, char const *s, int start, int len)
{
	char	*word;
	int		index;

	word = malloc_remix(lst_malloc, sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	index = 0;
	while (index < len)
	{
		word[index] = s[start + index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

/*	================================================================	*/

static int	fill_split(t_malloc **lst_malloc, char const *s, char c,
		char **result)
{
	int	index;
	int	start;
	int	length;
	int	word_start;

	index = 0;
	start = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		if (!s[start])
			break ;
		word_start = start;
		length = 0;
		while (s[start + length] && s[start + length] != c)
			length++;
		if (length > 0)
		{
			result[index] = word_dup(lst_malloc, s, word_start, length);
			if (!result[index])
				return (0);
			index++;
		}
		start += length;
	}
	result[index] = NULL;
	return (1);
}

/*	================================================================	*/

char	**ft_split(t_malloc **lst_malloc, char *s, char c)
{
	char	**result;
	int		words;

	if (!s || !lst_malloc)
		return (NULL);
	words = count_words(s, c);
	result = malloc_remix(lst_malloc, sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!fill_split(lst_malloc, s, c, result))
		return (NULL);
	return (result);
}

/*	================================================================	*/

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*	================================================================	*/
