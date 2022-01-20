/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:50:56 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:50:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	lst_clear(t_list **a)
{
	t_list	*tmp;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
	{
		free(*a);
		return ;
	}
	while ((*a)->next != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*a);
	tmp = NULL;
}

void	ft_clean_all(t_list **a, t_list **b, int **array)
{
	lst_clear(a);
	lst_clear(b);
	free(*array);
}
