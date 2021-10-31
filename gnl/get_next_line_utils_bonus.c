/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:07:37 by                   #+#    #+#             */
/*   Updated: 2021/10/31 13:07:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (size != 0)
	{
		while ((size - 1 > 0) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
			size--;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *string, int symbol)
{
	char	*p;
	size_t	size;

	if (string == NULL)
		return (NULL);
	p = (char *)string;
	size = ft_strlen(p) + 2;
	while (size-- >= 2)
	{
		if (*p == (char)symbol)
			return (p);
		p++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	size1;
	size_t	size2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = (char *)malloc((size1 + size2) * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, (size1 + size2) + 1);
	ft_strlcpy(&result[size1], s2, (size1 + size2) + 1);
	free(s1);
	return (result);
}
