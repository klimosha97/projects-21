/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:10:01 by                   #+#    #+#             */
/*   Updated: 2021/10/24 15:04:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf( const char *format, ...);
int	ft_put_u_int(unsigned int a);
int	ft_print_pointer(long long unsigned int a);
int	ft_put_hex(unsigned int a, unsigned int s);
int	ft_putdecimal(int a);

#endif
