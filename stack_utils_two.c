/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:05:22 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 20:51:05 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackdel_node(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (stack == NULL)
		return ;
	*stack = temp->next;
	free(temp);
}

void	ft_stackdel_last(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	free(temp);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (stack == NULL || new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;
	t_stack	*p;

	if (new != NULL)
	{
		p = *stack;
		last = NULL;
		while (p)
		{
			last = p;
			p = p->next;
		}
		if (last)
			last->next = new;
		else
			*stack = new;
	}
}

int	ft_stack_min(t_stack *stack)
{
	int		min;
	int		pos;
	t_stack	*head;

	head = stack;
	min = head->data;
	pos = 0;
	while (head)
	{
		if (min > head->data)
			min = head->data;
		head = head->next;
	}
	return (min);
}
