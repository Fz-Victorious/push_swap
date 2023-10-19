/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:00:20 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/13 12:28:42 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*ft_stacknew(int data)
{
	t_stack	*head;

	head = (t_stack *) malloc(sizeof(t_stack));
	if (head == NULL)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*p;

	if (stack == NULL || !stack->next)
		return (NULL);
	p = stack;
	while (p->next->next)
	p = p->next;
	return (p);
}

int	ft_stacksize(t_stack *stack)
{
	t_stack	*p;
	int		len;

	if (stack == NULL)
		return (0);
	p = stack;
	len = 0;
	while (p)
	{
		p = p->next;
		len++;
	}
	return (len);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*p;
	t_stack	*head;

	if (stack == NULL || *stack == NULL)
		return ;
	p = *stack;
	while (p)
	{
		head = p;
		p = p->next;
		free(head);
	}
	*stack = NULL;
}
