/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:40:46 by nrais             #+#    #+#             */
/*   Updated: 2025/03/23 08:45:22 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_free(char **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		i++;
	}
	//free(p);
	*p = NULL; //check 
	return (NULL);
}

static char	**subcount(char const *s, char c)
{
	int		j;
	char	**str;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		while (*s != c && *s)
			s++;
		j = j + 1;
	}
	str = (char **)malloc(sizeof(char *) * (j + 1));
	if (!str)
		return (NULL);
	str[j] = NULL;
	return (str);
}

static char	**ft_set(char const *s, char c)
{
	int		j;
	char	**p;

	j = 0;
	if (!s)
		return (NULL);
	p = subcount(s, c);
	if (!p)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		p[j] = (char *)malloc(sizeof(char) * (len(s, c) + 1));
		if (!p[j])
			return (ft_free(p, j));
		while (*s != c && *s)
			s++;
		j++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		j;
	int		k;

	j = 0;
	ptr = ft_set(s, c);
	if (!ptr)
		return (NULL);
	while (*s)
	{
		k = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			ptr[j][k] = *s;
			s++;
			k++;
		}
		if (ptr[j] != (void *)0)
			ptr[j][k] = '\0';
		j++;
	}
	return (ptr);
}

// static int	count_words(char const *s, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	if (!s)
// 		return (count);
// 	while (s[i])
// 	{
// 		if (s[i] != c && (i == 0 || s[i - 1] == c))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// static char	*copy(char const *start, char const *end)
// {
// 	int		i;
// 	char	*copy;

// 	i = 0;
// 	copy = (char *)malloc(end - start + 1);
// 	if (!copy)
// 		return (NULL);
// 	while (start < end)
// 		copy[i++] = *start++;
// 	copy[i] = '\0';
// 	return (copy);
// }

// static char	**free_splitted(char **splitted)
// {
// 	int	i;

// 	i = 0;
// 	while (splitted[i])
// 		i++;
// 	while (i > 0)
// 		free(splitted[--i]);
// 	free(splitted);
// 	return (NULL);
// }

// static char	**allocate(char const *s, char c)
// {
// 	char	**splitted;

// 	if (!s)
// 		return (NULL);
// 	splitted = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
// 	return (splitted);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char			**splitted;
// 	char const		*start;
// 	int				i;

// 	splitted = allocate(s, c);
// 	if (!splitted)
// 		return (NULL);
// 	i = 0;
// 	while (*s)
// 	{
// 		if (*s == c)
// 			s++;
// 		else
// 		{
// 			start = s;
// 			while (*s && *s != c)
// 				s++;
// 			splitted[i++] = copy(start, s);
// 			if (!splitted[i - 1])
// 				return (free_splitted(splitted));
// 		}
// 	}
// 	splitted[i] = NULL;
// 	return (splitted);
// }