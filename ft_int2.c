/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:34:44 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/22 16:52:52 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

#include <stdio.h>

char	*ft_negative(char *s, int *result)
{
	if (*s == '-')
	{
		s++;
		write(1, "-", 1);
		(*result)++;
	}
	return (s);
}

void	ft_write(char c, int len, int *result)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
		(*result)++;
	}
}

void	ft_no_flag(int width, int prcsn, int len, char *s, int *result)
{
	int space;
	int zero;

	zero = 0;
	space = 0;
	if (*s == '-')
	{
		len--;
		width--;
	}
	if (prcsn > len)
		zero = prcsn - len;
	space = (prcsn > len) ? width - prcsn : width - len;
	printf(" zero = %i ", space);
	ft_write(' ', space, result);
	s = ft_negative(s, result);
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len;
}

void	ft_zero_int(t_conv *conv, int len, char *s, int *result)
{
	int space;
	int zero;

	printf("zero");
	zero = 0;
	space = 0;
	if (*s == '-')
	{
		len--;
		conv->width--;
	}
	if (conv->prcsn > len)
		zero = conv->prcsn - len;
	if (conv->width > len && len > conv->prcsn)
	{
		if (conv->prcsn == -1)
			zero = conv->width - len;
		else
			space = conv->width - len;
	}
	if (conv->prcsn != -1)
		space = (conv->prcsn > len) ? conv->width - conv->prcsn : conv->width - len;
	ft_write(' ', space, result);
	s = ft_negative(s, result);
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len;
}

void	ft_dash_int(int width, int prcsn, int len, char *s, int *result)
{
	int space;
	int zero;

	printf("dash");
	zero = 0;
	if (*s == '-')
	{
		len--;
		width--;
	}
	s = ft_negative(s, result);
	if (prcsn > len)
		zero = prcsn - len;
	space = (prcsn > len) ? width - prcsn : width - len;
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len;
	ft_write(' ', space, result);
}

void	ft_integer(t_conv *conv, va_list ap, int *result)
{
	int i;
	int width;
	int prcsn;
	int len;
	char *s;

	i = va_arg(ap, int);
	conv->type = 'i';
	s = ft_itoa(i);
	width = conv->width;
	prcsn = conv->prcsn;
	len = ft_strlen(s);
	if (prcsn == 0)
	{
		if (*s == '0')
		{
			ft_write(' ', width, result);
			return ;
		}
	}
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag(width, prcsn, len, s, result);
	if (conv->flag == '0')
		ft_zero_int(conv, len, s, result);
	if (conv->flag == '-')
		ft_dash_int(width, prcsn, len, s, result);
}
