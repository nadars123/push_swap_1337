/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:46:34 by nrais             #+#    #+#             */
/*   Updated: 2025/03/15 23:22:42 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	nblen(char const *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i] && str[i] == '0')
		i++;
	while (str[i + j] && (str[i + j] >= '0' && str[i + j] <= '9'))
		j++;
	return (j);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			sign = -sign;
		i++;
	}
	if (nblen(str + i) > 19 && sign < 0)
		return (0);
	else if (nblen(str + i) > 19)
		return (-1);
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
