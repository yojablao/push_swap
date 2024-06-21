/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:29:46 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/21 18:21:41 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_up(t_list *b, int index)
{
	t_list	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = b;
	size = lstsize(b);
	while (tmp)
	{
		if (tmp->p == index)
		{
			if (i <= size / 2)
				return (0);
			else
				return (1);
		}
		i++;
		tmp = tmp->next;
	}
	tmp = b;
	return (0);
}

void	push_back_a(t_list **a, t_list **b)
{
	int	i;

	biger(b, &i);
	while (i >= 0)
	{
		if ((*b)->p == i)
		{
			pa(a, b);
			--i;
		}
		else if ((*b)->next->p == i)
		{
			sb(b);
			pa(a, b);
			--i;
		}
		else
		{
			if (get_up(*b, i))
				rrb(b);
			else
				rb(b);
		}
	}
}

void	ft_free(char **str)
{
	int		j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}

void	tl_free(t_list **t)
{
	t_list	*i;

	i = *t;
	while (i != NULL)
	{
		t = &(*t)->next;
		free(i);
		i = (*t);
	}
}

t_list	*lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof (t_list));
	if (node == NULL)
		return (NULL);
	node->p = 0;
	node->content = content;
	node->next = NULL;
	return (node);
}
