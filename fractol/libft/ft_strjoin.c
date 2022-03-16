/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:52:57 by                   #+#    #+#             */
/*   Updated: 2021/10/16 15:52:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	size1;
	size_t	size2;

	if (!(s1 && s2))
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = (char *)malloc((size1 + size2) * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, (size1 + size2) + 1);
	ft_strlcpy(&result[size1], s2, (size1 + size2) + 1);
	return (result);
}
