/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:21:26 by nrais             #+#    #+#             */
/*   Updated: 2025/03/23 08:40:15 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
		free(str[i--]);
	free(str[i]);
	*str = NULL;
	
}

void	ft_error(char *str)
{
	write(2, "Error\n", 6);
	free(str);
	exit(1);
}
