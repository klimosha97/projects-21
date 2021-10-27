/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:16:31 by                   #+#    #+#             */
/*   Updated: 2021/10/24 15:16:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_put_u_int(unsigned int a)
{
	unsigned int	ten_pow;
	unsigned int	b;
	int				i;

	ten_pow = 1;
	b = a / 10;
	i = 0;
	while (b > 0)
	{
		ten_pow *= 10;
		b /= 10;
	}
	while (ten_pow != 0)
	{
		ft_putchar_fd((a / ten_pow + 48), 1);
		i++;
		a %= ten_pow;
		ten_pow /= 10;
	}
	return (i);
}

int	ft_print_pointer(long long unsigned int a)
{
	int						i;
	long long unsigned int	hex_pow;
	long long unsigned int	b;

	write(1, "0x", 2);
	i = 2;
	b = a / 16;
	hex_pow = 1;
	while (b > 0)
	{
		hex_pow *= 16;
		b /= 16;
	}
	while (hex_pow != 0)
	{
		if (a / hex_pow > 9)
			ft_putchar_fd(a / hex_pow + 87, 1);
		else
			ft_putchar_fd(a / hex_pow + 48, 1);
		i++;
		a %= hex_pow;
		hex_pow /= 16;
	}
	return (i);
}

int	ft_put_hex(unsigned int a, unsigned int s)
{
	int				i;
	unsigned int	hex_pow;
	unsigned int	b;

	i = 0;
	b = a / 16;
	hex_pow = 1;
	while (b > 0)
	{
		hex_pow *= 16;
		b /= 16;
	}
	while (hex_pow != 0)
	{
		if (a / hex_pow > 9)
			ft_putchar_fd(a / hex_pow + s, 1);
		else
			ft_putchar_fd(a / hex_pow + 48, 1);
		i++;
		a %= hex_pow;
		hex_pow /= 16;
	}
	return (i);
}

int	ft_putdecimal(int a)
{
	int	n;
	int	ten_pow;
	int	i;

	n = a / 10;
	ten_pow = 1;
	i = 0;
	if (a < 0)
	{
		ft_putchar_fd('-', 1);
		i += 1;
	}
	while (n != 0)
	{
		n /= 10;
		ten_pow *= 10;
	}
	while (ten_pow != 0)
	{
		ft_putchar_fd(48 + ft_abs(a / ten_pow % 10), 1);
		i++;
		a %= ten_pow;
		ten_pow /= 10;
	}
	return (i);
}
