/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:25:23 by nrais             #+#    #+#             */
/*   Updated: 2025/03/23 08:41:12 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_free(t_stack **a, char **str)
{
	free_stack(a);
	free_matrix(str);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack **a)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = *a;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*a = NULL;
}
