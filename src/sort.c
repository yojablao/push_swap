/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:46:29 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/20 18:49:03 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **a, t_list **b, int valid_to)
{
	int	i;

	i = 0;
	while (lstsize(*a) > 0)
	{
		if ((*a)->p <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->p <= (valid_to + i))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	sort_3(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	if (tmp->p > tmp->next->p && tmp->next->p > tmp->next->next->p)
		return (ra(a), sa(a));
	else if (tmp->p > tmp->next->p
		&& tmp->next->p < tmp->next->next->p && tmp->p > tmp->next->next->p)
		return (ra(a));
	else if (tmp->p > tmp->next->p && tmp->p < tmp->next->next->p)
		return (sa(a));
	else if (tmp->p < tmp->next->p && tmp->p > tmp->next->next->p)
		return (rra(a));
	else if (tmp->p < tmp->next->p
		&& tmp->next->p > tmp->next->next->p && tmp->p < tmp->next->next->p)
		return (sa(a), ra(a));
}

void	sort_4(t_list **a, t_list **b)
{
	int	i;
	int	index;

	i = 0;
	index = small(a, &i);
	while (i != (*a)->p)
	{
		if (index > (3 / 2))
			rra(a);
		else
			sa(a);
		if ((*a)->p == i)
			break ;
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	int	i;
	int	index;

	i = 0;
	index = small(a, &i);
	while (i != (*a)->p)
	{
		if (index > (3 / 2))
			rra(a);
		else
			sa(a);
		if ((*a)->p == i)
			break ;
	}
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	sort(t_list **a, t_list **b, int size)
{
	t_list	*tmp;

	tmp = *a;
	if (size == 2)
	{
		if (tmp->next->content < tmp->content)
			sa(a);
		return ;
	}
	if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
	{
		if (lstsize(*a) <= 100)
			push_b(a, b, 15);
		else if (lstsize(*a) > 100)
			push_b(a, b, 30);
		push_back_a(a, b);
	}
}
