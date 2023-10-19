/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:42:53 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 15:04:16 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	minimum;

	minimum = ft_stack_min(*stack_a);
	while ((*stack_a)->data != minimum)
	{
		if ((*stack_a)->data != minimum && (*stack_a)->next->data != minimum)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else
			rotate_stack(stack_a, 0, "ra\n");
	}
	push_stack(stack_a, stack_b, "pb\n");
}

void	sorting_stack_len_two(t_stack **stack_a)
{
	swap_stack(*stack_a, 0, "sa\n");
	exit_push_swap(*stack_a, 0, 1);
}

int	ft_stack_max(t_stack *stack)
{
	int			max;
	int			pos;
	t_stack		*head;

	head = stack;
	max = head->data;
	pos = 0;
	while (head)
	{
		if (max < head->data)
			max = head->data;
		head = head->next;
	}
	return (max);
}

void	sorting_small_stack(t_stack **stack_a, t_stack **stack_b, int stack_len)
{
	int	min;
	int	max;

	if (stack_len == 2)
		sorting_stack_len_two(stack_a);
	min = ft_stack_min(*stack_a);
	max = ft_stack_max(*stack_a);
	while (!is_sorted(*stack_a))
	{
		if (((*stack_a)->data == max) && ((*stack_a)->next->data == min))
			rotate_stack(stack_a, stack_b, "ra\n");
		else if (((*stack_a)->data == min) || \
				((*stack_a)->data > (*stack_a)->next->data))
			swap_stack(*stack_a, 0, "sa\n");
		else
			reverse_rotate_stack(stack_a, 0, "rra\n");
	}
}

void	sorting_medium_stack(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stacksize(*stack_a) > 3)
		push_min_to_b(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sorting_small_stack(stack_a, stack_b, 3);
	while (ft_stacksize(*stack_b))
		push_stack(stack_b, stack_a, "pa\n");
}
