/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:37:31 by nrais             #+#    #+#             */
/*   Updated: 2025/04/04 16:31:40 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "string.h"

static char	*join_args(char **av, int ac)
{
	int		i;
	char	*argsjoin;
	char 	*tmp; 
	i = 1;
	argsjoin = ft_strdup("");
	while (i < ac)
	{
		if (is_empty(av[i]))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		tmp=argsjoin;
		argsjoin = ft_strjoin(argsjoin, av[i]);
		free(tmp);
		i++;
	}
	return (argsjoin);
}

void	parse(t_stack **a, char **av, int ac)
{
	char	*join;
	char	**splitargs;

	join = join_args(av, ac);
	if (!join)
		exit(EXIT_FAILURE);
	splitargs = ft_split(join, ' ');
	free(join);
	creat_stack(a, splitargs);
	free_matrix(splitargs);
}
