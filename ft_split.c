/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:09:55 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 20:56:32 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(char **tab)
{
	char	*p;
	char	**t;
	int		i;

	t = tab;
	i = 0;
	while (tab[i])
	{
		p = tab[i];
		i++;
		free(p);
		p = NULL;
	}
	free(t);
}

int	rowscal(char *s, char c)
{
	int	i;
	int	rows;

	i = 0;
	rows = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i]) && (s[i + 1] == c || s[i + 1] == '\0'))
			rows += 1;
		i++;
	}
	return (rows);
}

char	*storenewstr(char *s, char c, int *incr)
{
	char	*pt;
	int		cols;
	int		pos;

	cols = 0;
	pos = *incr;
	while (s[*incr] != c && s[*incr])
	{
		cols++;
		(*incr)++;
	}
	pt = ft_substr(s, pos, cols);
	return (pt);
}

char	**checker(char	**p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		rows;

	if (s == NULL)
		return (NULL);
	rows = rowscal((char *) s, c);
	ptr = (char **) malloc((rows + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < rows)
	{
		while (s[j] == c)
			j++;
		ptr[i] = storenewstr((char *) s, c, &j);
		if (ptr[i] == NULL)
			return (checker(ptr));
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
