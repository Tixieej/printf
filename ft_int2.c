/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:34:44 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/20 14:07:40 by rde-vrie      ########   odam.nl         */
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
	if (len > width && len > prcsn)
	{
		write(1, s, len);
		*result += len;
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
	ft_write(' ', space, result);
	s = ft_negative(s, result);
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len;
}

void	ft_zero_int(int width, int prcsn, int len, char *s, int *result)
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
	if (len > width && len > prcsn)
	{
		write(1, s, len);
		*result += len;
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

	zero = 0;
	if (*s == '-')
	{
		write(1, "-", 1);
		s++;
		len--;
		width--;
		(*result)++;
	}
	if (len > width && len > prcsn)
	{
		write(1, s, len);
		*result += len;
		return ;
	}
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
		while (*s == '0')
			s++;
	}
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag(width, prcsn, len, s, result);
	if (conv->flag == '0')
		ft_zero_int(width, prcsn, len, s, result);
	if (conv->flag == '-')
		ft_dash_int(width, prcsn, len, s, result);
}
