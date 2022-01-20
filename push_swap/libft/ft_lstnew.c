/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:52:19 by                   #+#    #+#             */
/*   Updated: 2021/12/27 00:07:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(long long content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	new->s_Ar = -1;
	new->s_Arr = -1;
	new->s_Br = -1;
	new->s_Brr = -1;
	new->all_score = -1;
	return (new);
}
