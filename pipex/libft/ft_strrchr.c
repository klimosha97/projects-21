/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:53:17 by                   #+#    #+#             */
/*   Updated: 2021/10/17 04:26:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	char	*p;
	size_t	size;
	size_t	i;

	p = (char *)string;
	size = ft_strlen(p);
	i = size + 2;
	while (i-- >= 2)
	{
		if (p[size] == (char)symbol)
			return (&p[size]);
		size--;
	}
	return (NULL);
}
