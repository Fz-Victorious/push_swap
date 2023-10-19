/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:05:51 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/16 13:20:38 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		ft_stackclear(&stack_a);
	if (stack_b)
		ft_stackclear(&stack_b);
	if (!status)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

int	is_integer(long long int n)
{
	if (n < -2147483648 || n > 2147483647)
		return (0);
	return (1);
}

int	is_duplicate(t_stack **stack)
{
	t_stack	*p;
	t_stack	*head;

	head = *stack;
	while (head->next)
	{
		p = head->next;
		while (p)
		{
			if (head->data == p->data)
				return (0);
			p = p->next;
		}
		head = head->next;
	}
	return (1);
}

int	is_num(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '+' || av[i] == '-') && \
			((av[i + 1]) >= '0' && av[i + 1] <= '9'))
		i++;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_and_create(char **av, t_stack **stack_a)
{
	int			i;
	long long	data;
	t_stack		*new_node;

	i = 0;
	while (av[i])
	{
		if (!(is_num(av[i])))
			free_and_exit(av, stack_a);
		data = ft_atoi(av[i]);
		if (!is_integer(data))
			free_and_exit(av, stack_a);
		new_node = ft_stacknew(data);
		if (new_node == NULL)
			free_and_exit(av, stack_a);
		ft_stackadd_back(stack_a, new_node);
		i++;
	}
}
