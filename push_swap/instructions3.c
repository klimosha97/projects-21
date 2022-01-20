/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:51:06 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:51:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rev_rotate_ab(t_list **a, t_list **b, int flag)
{
	rev_rotate_a(a, 0);
	rev_rotate_b(b, 0);
	if (flag)
		write(1, "rrr\n", 4);
}

void	go_all_to_B(t_list **a, t_list **b, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*a)->content == array[0] || (*a)->content == array[size - 1]
			|| (*a)->content == array[(size - 1) / 2])
		{
			rotate_a(a, 1);
			i++;
			continue ;
		}
		i++;
		push_b(a, b, 1);
	}
}

void	make_rr_pa(t_list **a, t_list **b, t_list *elem)
{
	make_rr(a, b, elem);
	push_a(a, b, 1);
}
