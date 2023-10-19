/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_from_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:36:11 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/13 12:46:01 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack *stack_a)
{
	t_stack	*head;
	int		pos;
	int		min;

	moves_top_a(&stack_a);
	min = stack_a->data;
	pos = stack_a->pos;
	head = stack_a->next;
	while (head)
	{
		if (head->data < min)
		{
			min = head->data;
			pos = head->pos;
		}
		head = head->next;
	}
	return (pos);
}

void	rotate_to_start_min(t_stack **stack_a)
{
	int	pos;
	int	len;
	int	abs_pos;

	len = ft_stacksize(*stack_a);
	pos = min_pos(*stack_a);
	abs_pos = ft_abs(pos);
	if (pos > 0)
	{
		while (abs_pos > 0)
		{
			rotate_stack(stack_a, 0, "ra\n");
			abs_pos--;
		}
	}
	else
	{
		while (abs_pos > 0)
		{
			reverse_rotate_stack(stack_a, 0, "rra\n");
			abs_pos--;
		}
	}
}
