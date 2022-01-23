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
	if (b->s_br >= b->s_ar)
		b->all_score = b->s_br;
	else
		b->all_score = b->s_ar;
	if (b->s_brr >= b->s_arr)
	{
		if (b->s_brr < b->all_score)
			b->all_score = b->s_brr;
	}
	else
	{
		if (b->s_arr < b->all_score)
			b->all_score = b->s_arr;
	}
	if ((b->s_ar + b->s_brr) < b->all_score)
		b->all_score = b->s_ar + b->s_brr;
	if ((b->s_br + b->s_arr) < b->all_score)
		b->all_score = b->s_br + b->s_arr;
}

void	make_rr(t_list **a, t_list **b, t_list *elem)
{
	if (elem->s_br >= elem->s_ar)
	{
		while (elem->s_ar-- != 0)
		{
			rotate_ab(a, b, 1);
			elem->s_br--;
		}
		while (elem->s_br-- != 0)
			rotate_b(b, 1);
	}
	else
	{
		while (elem->s_br-- != 0)
		{
			rotate_ab(a, b, 1);
			elem->s_ar--;
		}
		while (elem->s_ar-- != 0)
			rotate_a(a, 1);
	}
}

void	make_rrr(t_list **a, t_list **b, t_list *elem)
{
	if (elem->s_brr >= elem->s_arr)
	{
		while (elem->s_arr-- != 0)
		{
			rev_rotate_ab(a, b, 1);
			elem->s_brr--;
		}
		while (elem->s_brr-- != 0)
			rev_rotate_b(b, 1);
	}
	else
	{
		while (elem->s_brr-- != 0)
		{
			rev_rotate_ab(a, b, 1);
			elem->s_arr--;
		}
		while (elem->s_arr-- != 0)
			rev_rotate_a(a, 1);
	}
}

void	make_decision(t_list **a, t_list **b, t_list *elem)
{
	if (ft_max(elem->s_br, elem->s_ar) == elem->all_score)
		make_rr_pa(a, b, elem);
	else if (ft_max(elem->s_brr, elem->s_arr) == elem->all_score)
	{
		make_rrr(a, b, elem);
		push_a(a, b, 1);
	}
	else if ((elem->s_ar + elem->s_brr) == elem->all_score)
	{
		while (elem->s_ar-- != 0)
			rotate_a(a, 1);
		while (elem->s_brr-- != 0)
			rev_rotate_b(b, 1);
		push_a(a, b, 1);
	}
	else if ((elem->s_br + elem->s_arr) == elem->all_score)
	{
		while (elem->s_br-- != 0)
			rotate_b(b, 1);
		while (elem->s_arr-- != 0)
			rev_rotate_a(a, 1);
		push_a(a, b, 1);
	}
}
