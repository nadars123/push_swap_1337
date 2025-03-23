/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:21:52 by nrais             #+#    #+#             */
/*   Updated: 2025/03/15 23:22:20 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_position(t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		max_temp;
	int		pos;

	i = 0;
	pos = i;
	max_temp = (*b)->value;
	tmp = *b;
	while (i < ft_lstsize(*b) - 1)
	{
		tmp = tmp->next;
		i++;
		if (tmp->value > max_temp)
		{
			max_temp = tmp->value;
			pos = i;
		}
	}
	return (pos);
}

int	min_position(t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		min_temp;
	int		pos;

	i = 0;
	pos = i;
	min_temp = (*b)->value;
	tmp = *b;
	while (i < ft_lstsize(*b) - 1)
	{
		tmp = tmp->next;
		i++;
		if (tmp->value < min_temp)
		{
			min_temp = tmp->value;
			pos = i;
		}
	}
	return (pos);
}

void	move_to_b(t_stack **a, t_stack **b, int d)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		if ((*a)->curr_position <= i)
		{
			i++;
			pb(b, a);
		}
		else if ((*a)->curr_position <= i + ((size >= 150) * 36 + (size < 150)
				* 10))
		{
			i++;
			pb(b, a);
			rb(b);
		}
		else if (d)
			ra(a);
		else
			rra(a);
	}
}

void	move_to_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	size = ft_lstsize(*b);
	while (size--)
	{
		pos = max_position(b);
		if (pos <= ft_lstsize(*b) / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			while (pos++ < ft_lstsize(*b))
				rrb(b);
		}
		pa(a, b);
	}
}
