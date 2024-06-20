/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 04:46:41 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/20 21:12:33 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(char *str, int i)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(i);
}

int	set_index(t_list **a)
{
	t_list	*x;
	t_list	*y;

	x = (*a);
	while (x && x->next)
	{
		y = x->next;
		while (y)
		{
			if (x->content == y->content)
				return (0);
			else if (x->content > y->content)
				x->p++;
			else
				y->p++;
			y = y->next;
		}
		x = x->next;
	}
	return (1);
}

int	stack_set(t_list **a, char **nb, int size)
{
	t_list			*new_node;
	t_list			*current;
	int				i;

	i = 0;
	while (i < size)
	{
		new_node = lstnew(ft_atoi(nb[i]));
		if (!new_node)
			return (0);
		if (*a == NULL)
			*a = new_node;
		else
		{
			current = *a;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
		}
		i++;
	}
	if (set_index(a) == 0)
		return (0);
	return (1);
}

int	main(int c, char **v)
{
	t_list	*a;
	t_list	*b;
	int		p;

	a = NULL;
	b = NULL;
	p = pars_check(v, c, &a);
	if (sort_deja(a) == 0)
		return (0);
	if (p == 0)
	{
		free (a);
		free (b);
		return (1);
	}
	sort(&a, &b, lstsize(a));
	free(a);
	free(b);
	return (0);
}
