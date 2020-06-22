/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 11:45:54 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/02/02 11:43:05 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_char(const char fmt, t_conv *conv, va_list ap, int *result)
{
	char	c;
	int		width;

	if (fmt == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	conv->type = 'c';
	width = conv->width;
	if (width != 0)
	{
		if (conv->flag != '-' && conv->flag != '0')
			ft_spaces(width, -1, 1, result);
		if (conv->flag == '0')
			ft_zeroes(width, -1, 1, result);
	}
	write(1, &c, 1);
	(*result)++;
	if (conv->flag == '-')
		ft_spaces(width, -1, 1, result);
}
