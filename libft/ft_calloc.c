/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:51:53 by                   #+#    #+#             */
/*   Updated: 2021/10/16 15:51:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = count * size;
	ptr = (char *)malloc(i);
	if (ptr == NULL)
		return (NULL);
	while (i-- > 0)
		ptr[i] = 0;
	return (ptr);
}