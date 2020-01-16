/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:28:55 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/16 16:06:08 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

void	ft_pointer(const char *fmt, t_conv *conv, va_list ap, int *result)
{
	void				*p;
	unsigned long long	address;

	p = va_arg(ap, void *);
	(void)fmt;
	(void)conv;
	(*result)++;
	address = 0; //tijdelijk
}
