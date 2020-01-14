/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 12:58:00 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/09 16:57:27 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

#include <stdio.h> //WEHEGALElolll
void	ft_write_string(int prcsn, int len, char *s)
{
	int j;

	if (prcsn != -1)
	{
		j = (prcsn < len) ? prcsn : len;
		write(1, s, j);
	}
	else
		write (1, s, len);
}

void	ft_zeroes(int width, int prcsn, int len)
{
	int min;

	if (prcsn != -1)
		min = (prcsn < len) ? prcsn : len;
	else
		min = len;
	while (width - min > 0)
	{
		write(1, "0", 1);
		min++;
	}
}
void	ft_spaces(int width, int prcsn, int len)
{
	int min;

	if (prcsn != -1)
		min = (prcsn < len) ? prcsn : len;
	else
		min = len;
	while (width - min > 0)
	{
		write(1, " ", 1);
		min++;
	}
}

void	ft_string(const char *fmt, t_conv *conv, va_list ap)
{
	char	*s;
	int		width;
	int		len;
	int		prcsn;

	(void)fmt;   // WEHGHAEN LLOL
	s = va_arg(ap, char*);
	conv->type = 's';
	width = conv->width;
	prcsn = conv->prcsn;
	len = ft_strlen(s);
	if (width != 0)
	{
		if (conv->flag != '-' && conv->flag != '0')
			ft_spaces(width, prcsn, len);
		if (conv->flag == '0')
			ft_zeroes(width, prcsn, len);
	}
	ft_write_string(prcsn, len, s);
	if (conv->flag == '-')
		ft_spaces(width, prcsn, len);
}
