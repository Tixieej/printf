/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion_router.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 11:47:02 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/02/02 11:44:21 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

const char	*type(const char *fmt, va_list ap, t_conv *conversion, int *result)
{
	if (*fmt == 'c' || *fmt == '%')
		ft_char(*fmt, conversion, ap, result);
	else if (*fmt == 's')
		ft_string(conversion, ap, result);
	else if (*fmt == 'p')
		ft_pointer(conversion, ap, result);
	else if (*fmt == 'i' || *fmt == 'd')
		ft_integer(conversion, ap, result);
	else if (*fmt == 'u')
		ft_uint(conversion, ap, result);
	else if (*fmt == 'x' || *fmt == 'X')
		ft_hex(*fmt, conversion, ap, result);
	fmt++;
	return (fmt);
}
