/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:34:44 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/14 13:39:22 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

#include <stdio.h>
void	ft_write(char c, int len)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
	}
}

void	ft_no_flag(int width, int prcsn, int len, char *s)
{
	int space;
	int zero;

	zero = 0;
	if (len > width && len > prcsn)
	{
		write(1, s, len); //hier gaat het fout, je INT_MIN wordt met len-1 geprint!
		return ;
	}
	if (*s == '-')
	{
		len--;
		width--;
	}
	if (prcsn > len)
		zero = prcsn - len;
	space = (prcsn > len) ? width - prcsn : width - len;
	ft_write(' ', space);
	if (*s == '-')
	{
		s++;
		write(1, "-", 1);
	}
	ft_write('0', zero);
	write(1, s, len);
}

void	ft_zero_int(int width, int prcsn, int len, char *s)
{
	int space;
	int zero;

	zero = 0;
	if (*s == '-')
	{
		len--;
		width--;
	}
	if (len > width && len > prcsn)
	{
		write(1, s, len);
		return ;
	}
	if (prcsn > len)
		zero = prcsn - len;
	if (width > len && len > prcsn)
	{
		if (prcsn == -1)
			zero = width - len;
		else
			space = width - len;
	}
	if (prcsn != -1)
		space = (prcsn > len) ? width - prcsn : width - len;
	ft_write(' ', space);
	if (*s == '-')
	{
		s++;
		write(1, "-", 1);
	}
	ft_write('0', zero);
	write(1, s, len);
}

void	ft_dash_int(int width, int prcsn, int len, char *s)
{
	int space;
	int zero;

	zero = 0;
	if (*s == '-')
	{
		write(1, "-", 1);
		s++;
		len--;
		width--;
	}
	if (len > width && len > prcsn)
	{
		write(1, s, len);
		return ;
	}
	if (prcsn > len)
		zero = prcsn - len;
	space = (prcsn > len) ? width - prcsn : width - len;
	ft_write('0', zero);
	write(1, s, len);
	ft_write(' ', space);
}

void	ft_integer(const char *fmt, t_conv *conv, va_list ap)
{
	int i;
	int width;
	int prcsn;
	int len;
	char *s;

	(void)fmt; //weghalen
	i = va_arg(ap, int);
	conv->type = 'i';
	s = ft_itoa(i);
	width = conv->width;
	prcsn = conv->prcsn;
	len = ft_strlen(s);
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag(width, prcsn, len, s);
	if (conv->flag == '0')
		ft_zero_int(width, prcsn, len, s);
	if (conv->flag == '-')
		ft_dash_int(width, prcsn, len, s);
}
