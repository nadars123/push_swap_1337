/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:39:27 by nrais             #+#    #+#             */
/*   Updated: 2025/04/04 16:30:51 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;

	i = 0;
	// if (s1 == NULL)
	// 	s1 = "";
	// if (s2 == NULL)
	// 	s2 = "";
	arr = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!arr)
		return (NULL);
	while (*s1)
		arr[i++] = *(s1++);
	arr[i++] = ' ';
	while (*s2)
		arr[i++] = *(s2++);
	arr[i] = '\0';
	return (arr);
	
}


char *ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	is_empty(char *str)
{
	int	i;
	int	count;

	if (ft_strlen(str) == 0)
		return (1);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (1);
	return (0);
}
