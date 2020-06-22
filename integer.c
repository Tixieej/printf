/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   integer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 11:44:18 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/02/02 11:41:35 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft2/libft.h"
#include <unistd.h>

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

void	ft_no_flag(t_conv *con, int len, char *s, int *result)
{
	int space;
	int zero;

	zero = 0;
	space = 0;
	if (*s == '-')
	{
		len--;
		con->width--;
	}
	if (con->prcsn > len)
		zero = con->prcsn - len;
	space = (con->prcsn > len) ? con->width - con->prcsn : con->width - len;
	ft_write(' ', space, result);
	s = ft_negative(s, result);
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len;
}

void	ft_zero_int(t_conv *con, int len, char *s, int *result)
{
	int space;
	int zero;

	zero = 0;
	space = 0;
	if (*s == '-')
	{
		len--;
		con->width--;
	}
	if (con->prcsn > len)
		zero = con->prcsn - len;
	if (con->width > len && len > con->prcsn)
	{
		if (con->prcsn == -1)
			zero = con->width - len;
	}
	if (con->prcsn != -1)
		space = (con->prcsn > len) ? con->width - con->prcsn : con->width - len;
	ft_write(' ', space, result);
	s = ft_negative(s, result);
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len;
}

void	ft_dash_int(t_conv *con, int len, char *s, int *result)
{
	int space;
	int zero;

	zero = 0;
	if (*s == '-')
	{
		len--;
		con->width--;
	}
	s = ft_negative(s, result);
	if (con->prcsn > len)
		zero = con->prcsn - len;
	space = (con->prcsn > len) ? con->width - con->prcsn : con->width - len;
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len;
	ft_write(' ', space, result);
}

void	ft_integer(t_conv *conv, va_list ap, int *result)
{
	int		i;
	int		len;
	char	*s;

	i = va_arg(ap, int);
	conv->type = 'i';
	s = ft_itoa(i);
	if (!s)
		return ;
	len = ft_strlen(s);
	if (conv->prcsn == 0 && *s == '0')
	{
		ft_write(' ', conv->width, result);
		free(s);
		return ;
	}
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag(conv, len, s, result);
	if (conv->flag == '0')
		ft_zero_int(conv, len, s, result);
	if (conv->flag == '-')
		ft_dash_int(conv, len, s, result);
	free(s);
}
