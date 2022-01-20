/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:52:40 by                   #+#    #+#             */
/*   Updated: 2021/10/16 15:52:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	size_t			a;
	unsigned char	*b;

	a = 0;
	b = (unsigned char *)memptr;
	while (a < num)
		b[a++] = val;
	return (b);
}