/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:50:46 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:50:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	triple_check(t_list **a)
{
	if (check_sorted(*a) > 0)
		return ;
	if ((*a)->next->content > (*a)->content && (*a)->next->content > (*a)
		->next->next->content)
		rotate_a(a, 1);
	swap_a(a, 1);
}

void	triple_sort(t_list **a)
{
	if ((*a)->content < (*a)->next->content && (*a)->content < (*a)->next
		->next->content && (*a)->next->content > (*a)->next->next->content)
	{
		rev_rotate_a(a, 1);
		swap_a(a, 1);
	}
	else if ((*a)->content > (*a)->next->content && (*a)->content > (*a)->next
		->next->content && (*a)->next->content < (*a)->next->next->content)
		rotate_a(a, 1);
	else if ((*a)->content > (*a)->next->content && (*a)->content > (*a)->next
		->next->content && (*a)->next->content > (*a)->next->next->content)
	{
		swap_a(a, 1);
		rev_rotate_a(a, 1);
	}
	else if ((*a)->content > (*a)->next->content && (*a)->content < (*a)->next
		->next->content && (*a)->next->content < (*a)->next->next->content)
		swap_a(a, 1);
	else if ((*a)->content < (*a)->next->content && (*a)->content > (*a)->next
		->next->content && (*a)->next->content > (*a)->next->next->content)
		rev_rotate_a(a, 1);
}

void	merge_helper(t_list **a, t_list **b)
{
	while ((*b))
	{
		if ((*b)->content > (*a)->content)
		{
			if ((*a)->content > (*a)->next->content)
			{
				rotate_a(a, 1);
				push_a(a, b, 1);
				continue ;
			}
			rotate_a(a, 1);
		}
		else
			push_a(a, b, 1);
	}
}

void	merge_a_b(t_list **a, t_list **b)
{
	long long	min;
	long long	max;

	min = (*a)->content;
	max = (*a)->next->next->content;
	while ((*b))
	{
		if ((*b)->content < min)
		{
			min = (*b)->content;
			push_a(a, b, 1);
		}
		else if ((*b)->content > max)
		{
			max = (*b)->content;
			push_a(a, b, 1);
			rotate_a(a, 1);
		}
		else
		{
			merge_helper(a, b);
			return ;
		}
	}
}

void	sort3to5(t_list **a, t_list **b, int agc)
{
	if (agc == 3)
	{
		triple_sort(a);
		return ;
	}
	while (agc-- > 3)
		push_b(a, b, 1);
	triple_sort(a);
	if ((*b)->next != NULL && (*b)->content > (*b)->next->content)
		swap_b(b, 1);
	merge_a_b(a, b);
}
