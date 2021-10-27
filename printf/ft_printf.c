/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:16:33 by                   #+#    #+#             */
/*   Updated: 2021/10/24 15:16:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ((int)write(1, "(null)", 6));
	while (str[i] != '\0')
		i += (int)write(1, &str[i], 1);
	return (i);
}

int	ft_parse_flags(int a, va_list v)
{
	if (a == 0)
	{
		ft_putchar_fd(va_arg(v, int), 1);
		return (1);
	}
	if (a == 1)
		return (ft_printstr(va_arg(v, char *)));
	if (a == 2)
		return (ft_print_pointer(va_arg(v, long long int)));
	if (a == 3 || a == 4)
		return (ft_putdecimal(va_arg(v, int)));
	if (a == 5)
		return (ft_put_u_int(va_arg(v, unsigned int)));
	if (a == 6)
		return (ft_put_hex(va_arg(v, unsigned int), 87));
	if (a == 7)
		return (ft_put_hex(va_arg(v, unsigned int), 55));
	if (a == 8)
		return ((int)write(1, "%", 1));
	return (-1);
}

int	search_type(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_parse_ch(char *str, va_list v)
{
	int		i;
	int		f;

	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			f = search_type("cspdiuxX%", *str);
			if (f == -1)
				return (-1);
			i += ft_parse_flags(f, v);
			str++;
			continue ;
		}
		i += (int)write(1, str, 1);
		str++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	va;

	va_start(va, format);
	i = ft_parse_ch((char *)format, va);
	va_end(va);
	return (i);
}
