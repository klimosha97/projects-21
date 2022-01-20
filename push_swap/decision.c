/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:50:59 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:50:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	make_allscore(t_list *b)
{
	if (b->s_Br >= b->s_Ar)
		b->all_score = b->s_Br;
	else
		b->all_score = b->s_Ar;
	if (b->s_Brr >= b->s_Arr)
	{
		if (b->s_Brr < b->all_score)
			b->all_score = b->s_Brr;
	}
	else
	{
		if (b->s_Arr < b->all_score)
			b->all_score = b->s_Arr;
	}
	if ((b->s_Ar + b->s_Brr) < b->all_score)
		b->all_score = b->s_Ar + b->s_Brr;
	if ((b->s_Br + b->s_Arr) < b->all_score)
		b->all_score = b->s_Br + b->s_Arr;
}

void	make_rr(t_list **a, t_list **b, t_list *elem)
{
	if (elem->s_Br >= elem->s_Ar)
	{
		while (elem->s_Ar-- != 0)
		{
			rotate_ab(a, b, 1);
			elem->s_Br--;
		}
		while (elem->s_Br-- != 0)
			rotate_b(b, 1);
	}
	else
	{
		while (elem->s_Br-- != 0)
		{
			rotate_ab(a, b, 1);
			elem->s_Ar--;
		}
		while (elem->s_Ar-- != 0)
			rotate_a(a, 1);
	}
}

void	make_rrr(t_list **a, t_list **b, t_list *elem)
{
	if (elem->s_Brr >= elem->s_Arr)
	{
		while (elem->s_Arr-- != 0)
		{
			rev_rotate_ab(a, b, 1);
			elem->s_Brr--;
		}
		while (elem->s_Brr-- != 0)
			rev_rotate_b(b, 1);
	}
	else
	{
		while (elem->s_Brr-- != 0)
		{
			rev_rotate_ab(a, b, 1);
			elem->s_Arr--;
		}
		while (elem->s_Arr-- != 0)
			rev_rotate_a(a, 1);
	}
}

void	make_decision(t_list **a, t_list **b, t_list *elem)
{
	if (ft_max(elem->s_Br, elem->s_Ar) == elem->all_score)
		make_rr_pa(a, b, elem);
	else if (ft_max(elem->s_Brr, elem->s_Arr) == elem->all_score)
	{
		make_rrr(a, b, elem);
		push_a(a, b, 1);
	}
	else if ((elem->s_Ar + elem->s_Brr) == elem->all_score)
	{
		while (elem->s_Ar-- != 0)
			rotate_a(a, 1);
		while (elem->s_Brr-- != 0)
			rev_rotate_b(b, 1);
		push_a(a, b, 1);
	}
	else if ((elem->s_Br + elem->s_Arr) == elem->all_score)
	{
		while (elem->s_Br-- != 0)
			rotate_b(b, 1);
		while (elem->s_Arr-- != 0)
			rev_rotate_a(a, 1);
		push_a(a, b, 1);
	}
}
