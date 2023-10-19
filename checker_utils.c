/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:25:20 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 19:19:26 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_movesadd_back(t_moves **alst, t_moves *new)
{
	t_moves	*p;
	t_moves	*last;

	if (alst == NULL || new == NULL)
		return ;
	p = *alst;
	last = NULL;
	while (p != NULL)
	{
		last = p;
		p = p->next;
	}
	if (last)
		last->next = new;
	else
		*alst = new;
}

void	ft_moves_clear(t_moves	**move)
{
	t_moves	*p;
	t_moves	*head;

	if (move == NULL || *move == NULL)
		return ;
	p = *move;
	while (p)
	{
		head = p;
		p = p->next;
		free(head);
	}
	*move = NULL;
}

void	ft_movesdel_node(t_moves **move)
{
	t_moves	*temp;

	temp = *move;
	if (move == NULL)
		return ;
	*move = temp->next;
	free(temp);
}

t_moves	*ft_moves_new(void	*content)
{
	t_moves	*head;

	head = (t_moves *) malloc(sizeof(t_moves));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
