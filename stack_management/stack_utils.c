/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:49:41 by nrais             #+#    #+#             */
/*   Updated: 2025/03/15 23:23:00 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

int	ft_lstsize(t_stack *lst)
{
	int		count;
	t_stack	*current;

	current = lst;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_stack	*small_value(t_stack *node)
{
	int		min;
	t_stack	*small;

	if (node == NULL)
		return (NULL);
	min = INT_MAX;
	while (node)
	{
		if (node->value <= min)
		{
			small = node;
			min = node->value;
		}
		node = node->next;
	}
	return (small);
}

t_stack	*find_highest(t_stack *head)
{
	int		hightest;
	t_stack	*hight_node;

	if (head == NULL)
		return (NULL);
	hightest = INT_MIN;
	while (head)
	{
		if (head->value > hightest)
		{
			hightest = head->value;
			hight_node = head;
		}
		head = head->next;
	}
	return (hight_node);
}
