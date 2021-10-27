/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:29:16 by mcorneli          #+#    #+#             */
/*   Updated: 2021/10/15 16:29:30 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_int(const char *str)
{
	int	i;

	i = 0;
	while (*str > 47 && *str < 58)
	{
		i = (i * 10) + *str - 48;
		str++;
	}
	return (i);
}

int	ft_atoi(const char *string)
{
	while ((*string == 32) || (*string > 8 && *string < 14))
		string++;
	if (*string > 47 && *string < 58)
		return (count_int(string));
	if (*string == 45 && (*(string + 1) > 47 && *(string + 1) < 58))
		return ((count_int(string + 1) * -1));
	if (*string == 43 && (*(string + 1) > 47 && *(string + 1) < 58))
		return (count_int(string + 1));
	return (0);
}
