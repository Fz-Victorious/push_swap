/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_in_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:36:59 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/09 18:30:45 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_top_a(t_stack **stack_a)
{
	int		i;
	int		len;
	t_stack	*p;

	len = ft_stacksize(*stack_a);
	i = 0;
	p = (*stack_a);
	while (i <= len / 2)
	{
		p->pos = i;
		p = p->next;
		i++;
	}
	while (i < len)
	{
		p->pos = -1 * (len - i);
		p = p->next;
		i++;
	}
}

int	max_a_pos(t_stack *stack_a, int len)
{
	int	pos;
	int	max;
	int	i;

	i = 0;
	pos = stack_a->pos;
	max = stack_a->data;
	while (i < len)
	{
		if (stack_a->data > max)
		{
			max = stack_a->data;
			pos = stack_a->pos;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (pos + 1);
}

int	is_bigger_than_max(t_stack **stack_a, int number)
{
	t_stack	*p;

	p = (*stack_a);
	while (p)
	{
		if (number < p->data)
			return (0);
		p = p->next;
	}
	return (1);
}

int	find_position(t_stack **stack_a, int len, int number)
{
	int		i;
	t_stack	*p;
	t_stack	*last;

	last = ft_stack_last(*stack_a);
	if (number > last->next->data && number < (*stack_a)->data)
		return (0);
	if (is_bigger_than_max(stack_a, number))
		return (max_a_pos(*stack_a, len));
	p = *stack_a;
	i = 0;
	while (i < len - 1)
	{
		if (number > p->data && number < p->next->data)
			return (p->pos + 1);
		p = p->next;
	}
	return (0);
}

void	elem_moves_in_a(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int		i;
	int		len_a;
	int		len_b;
	int		num;
	t_stack	*p;

	len_a = ft_stacksize((*stack_a));
	len_b = ft_stacksize((*stack_b));
	moves_top_a(stack_a);
	i = 0;
	p = (*stack_b);
	while (i < len_b)
	{
		num = p->data;
		arr[i] = find_position(stack_a, len_a, num);
		i++;
		p = p->next;
	}
}
