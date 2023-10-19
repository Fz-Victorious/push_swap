/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:36:44 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 20:06:32 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeing_memory(int **arr1, int **arr2)
{
	free(*arr1);
	free(*arr2);
}

void	alloc_for_arrays_moves(t_stack **stack_a, t_stack **stack_b, \
		int **a_mov, int **b_mov)
{
	*a_mov = malloc(ft_stacksize(*stack_b) * sizeof(int));
	if (!*a_mov)
		exit_push_swap(*stack_a, *stack_b, 0);
	*b_mov = malloc(ft_stacksize(*stack_b) * sizeof(int));
	if (!*b_mov)
		exit_push_swap(*stack_a, *stack_b, 0);
}

void	sorting_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	*lis;
	int	len_lis;
	int	*a_mov;
	int	*b_mov;
	int	mv_i;

	a_mov = NULL;
	b_mov = NULL;
	lis = longest_inc_sub(*stack_a, &len_lis);
	if (!lis)
		exit_push_swap(*stack_a, *stack_b, 0);
	push_to_b(stack_a, stack_b, lis, len_lis);
	free(lis);
	while (ft_stacksize(*stack_b))
	{
		alloc_for_arrays_moves(stack_a, stack_b, &a_mov, &b_mov);
		elem_moves_in_a(stack_a, stack_b, a_mov);
		elem_moves_in_b(stack_b, b_mov);
		mv_i = min_moves_index(a_mov, b_mov, ft_stacksize(*stack_b));
		if (mv_i == -1)
			exit_push_swap(*stack_a, *stack_b, 0);
		sort_elem_with_min_moves(stack_a, stack_b, a_mov[mv_i], b_mov[mv_i]);
		freeing_memory(&a_mov, &b_mov);
	}
	rotate_to_start_min(stack_a);
}

void	manage_args(char **av, t_stack **stack_a)
{
	int		i;
	char	**arg;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			exit_push_swap(*stack_a, 0, 0);
		arg = ft_split(av[i], ' ');
		if (arg == NULL)
			exit_push_swap(*stack_a, 0, 0);
		check_and_create(arg, stack_a);
		i++;
		free_mem(arg);
	}
	if (!is_duplicate(stack_a))
		exit_push_swap(*stack_a, 0, 0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_len;

	if (ac == 1)
		exit(0);
	stack_a = 0;
	stack_b = 0;
	stack_len = 0;
	manage_args(&av[1], &stack_a);
	if (!is_sorted(stack_a))
	{
		stack_len = ft_stacksize(stack_a);
		if (stack_len <= 3)
			sorting_small_stack(&stack_a, &stack_b, stack_len);
		else if (stack_len < 6)
			sorting_medium_stack(&stack_a, &stack_b);
		else
			sorting_big_stack(&stack_a, &stack_b);
	}
	exit_push_swap(stack_a, stack_b, 1);
	return (0);
}
