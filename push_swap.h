/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:24:16 by nrais             #+#    #+#             */
/*   Updated: 2025/04/04 16:14:58 by nrais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				curr_position;
	struct s_stack	*next;
}					t_stack;

// PARSING
void				parse(t_stack **a, char **argv, int argc);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strlen(char *s);
int					is_empty(char *str);
char				*ft_strdup(char *s1);

// STACK_MANAGEMENT
void				creat_stack(t_stack **a, char **str);
int					ft_atoi(const char *str);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_lstsize(t_stack *lst);
t_stack				*small_value(t_stack *node);
t_stack				*find_highest(t_stack *head);

// SORTING
void				sort(t_stack **a, t_stack **b);
int					max_position(t_stack **b);
int					min_position(t_stack **b);
void				move_to_b(t_stack **a, t_stack **b, int d);
void				move_to_a(t_stack **a, t_stack **b);
int					check_sort(t_stack *a);
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_4(t_stack **a, t_stack **b);
void				sort_5(t_stack **a, t_stack **b);

// COMMANDS
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// ERRORS
void				free_matrix(char **str);
int					is_number(char c);
int					error_sytax(char *str);
int					error_repetition(t_stack *a, int nbr);
void				error_free(t_stack **a, char **str);
void				free_stack(t_stack **a);
void				free_matrix(char **str);
void				ft_error(char *str);
#endif
