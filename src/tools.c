/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:27:05 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/20 22:26:11 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	signe(const char *str, int *c)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	*c = i;
	return (sign);
}

int	e_atoi(char *str)
{
	int					i;
	int					sign;
	long long			result;

	sign = signe(str, &i);
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if ((result * sign) > MAX_INT || (result * sign) < MIN_INT || str[i])
		return (0);
	return (1);
}

int	sort_deja(t_list *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->content < a->next->content)
			a = a->next;
		else
			return (1);
	}
	return (0);
}

int	small(t_list **a, int *p)
{
	int		i;
	int		j;
	t_list	*tmp;
	int		result;

	i = 0;
	j = 0;
	tmp = *a;
	result = tmp->p;
	while (tmp)
	{
		if (tmp->p < result)
		{
			result = tmp->p;
			i = j;
		}
		tmp = tmp->next;
		j++;
	}
	*p = result;
	return (i);
}

int	biger(t_list **a, int *p)
{
	int		i;
	int		j;
	int		result;
	t_list	*tmp;

	i = 0;
	j = 0;
	tmp = *a;
	result = tmp->p;
	while (tmp)
	{
		if (tmp->p > result)
		{
			result = tmp->p;
			i = j;
		}
		tmp = tmp->next;
		j++;
	}
	*p = result;
	return (i);
}
