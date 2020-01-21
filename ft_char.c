/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 15:49:36 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/21 11:56:34 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

void ft_char(const char fmt, t_conv *conv, va_list ap, int *result)
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
	{
		//printf("\n- flag is hier\n");
		ft_spaces(width, -1, 1, result);
	}
}
