/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:12:35 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/21 19:50:05 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(char **v)
{
	int	i;
	int	j;

	if (!v)
		return (0);
	i = 0;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			if (ft_atoi(v[i]) == ft_atoi(v[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isnum(char **num)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (num[i])
	{
		j = 0;
		while (num[i][j])
		{
			if (!ft_isdigit(num[i][j]) && num[i][0] != '-' && num[i][0] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_e(char **s, int c)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (s[i] && c > i)
	{
		j = 0;
		while (s[i][j] == ' ')
			j++;
		if (s[i][j] == '\0')
			return (0);
		if (s[i][j] != ' ')
			i++;
	}
	return (1);
}

int	is_valid(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if ((v[i][j] == '-' || v[i][j] == '+')
				&& (!ft_isdigit(v[i][j + 1]) && v[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	pars_check(char **v, int c, t_list **a)
{
	int		i;
	char	**args;

	i = 0;
	if (check_e(v, c) == 0 || is_valid(v) == 0)
		return (put_error("Error", 2), 0);
	args = spliter(v, c);
	if (!args)
		return (ft_free(args), 0);
	while (args[i])
	{
		if (e_atoi(args[i]) == 0)
			return (ft_free(args), put_error("Error", 1), 0);
		i++;
	}
	if (ft_contains(args) == 0 || ft_isnum(args) == 0)
		return (ft_free(args), tl_free(a), put_error("Error", 1), 0);
	if (stack_set(a, args, i) == 0)
		return (ft_free(args), tl_free(a), 1);
	ft_free(args);
	return (1);
}
