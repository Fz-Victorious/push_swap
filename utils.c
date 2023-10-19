/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:18:27 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/16 13:15:50 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int				i;
	int				n;
	int				negtv;
	long int		sum;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	negtv = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negtv = -1;
		i++;
	}
	sum = 0;
	n = 0;
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
	{
		n = (str[i] - 48);
		sum = ((sum * 10) + n * negtv);
		i++;
	}
	return (sum);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
