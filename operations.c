/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:21:13 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 12:14:39 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *data_a, int *data_b)
{
	int	temp;

	temp = *data_a;
	*data_a = *data_b;
	*data_b = temp;
}

void	swap_stack(t_stack *main_stack, t_stack *other_stack, char *message)
{
	if (main_stack && main_stack->next)
		ft_swap(&(main_stack->data), &(main_stack->next->data));
	if (other_stack && other_stack->next)
		ft_swap(&(other_stack->data), &(other_stack->next->data));
	if (message != NULL)
		ft_putstr(message);
}

void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message)
{
	t_stack	*new;

	if (!(*from_stack))
		return ;
	new = ft_stacknew((*from_stack)->data);
	ft_stackadd_front(to_stack, new);
	ft_stackdel_node(from_stack);
	if (message != NULL)
		ft_putstr(message);
}

void	rotate_stack(t_stack **main_stack, t_stack **other_stack, char *message)
{
	int		data;
	t_stack	*rotate_node;

	if (main_stack && *main_stack)
	{
		data = (*main_stack)->data;
		ft_stackdel_node(main_stack);
		rotate_node = ft_stacknew(data);
		ft_stackadd_back(main_stack, rotate_node);
	}
	if (other_stack && *other_stack)
	{
		data = (*other_stack)->data;
		ft_stackdel_node(other_stack);
		rotate_node = ft_stacknew(data);
		ft_stackadd_back(other_stack, rotate_node);
	}
	if (message != NULL)
		ft_putstr(message);
}

void	reverse_rotate_stack(t_stack **main_stack, t_stack **other_stack, \
		char *message)
{
	int		data;
	t_stack	*last_node;
	t_stack	*rev_rot_node;

	if (main_stack && *main_stack && (*main_stack)->next)
	{
		last_node = ft_stack_last(*main_stack);
		if (last_node && last_node->next)
		{
			data = last_node->next->data;
			ft_stackdel_last(&last_node);
			rev_rot_node = ft_stacknew(data);
			ft_stackadd_front(main_stack, rev_rot_node);
		}
	}
	if (other_stack && *other_stack && (*other_stack)->next)
	{
		last_node = ft_stack_last(*other_stack);
		data = last_node->next->data;
		ft_stackdel_last(&last_node);
		rev_rot_node = ft_stacknew(data);
		ft_stackadd_front(other_stack, rev_rot_node);
	}
	if (message != NULL)
		ft_putstr(message);
}
