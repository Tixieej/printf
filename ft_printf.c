/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 13:54:35 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/02/02 11:41:24 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft2/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

const char	*ft_precision(const char *fmt, va_list ap, t_conv *conv)
{
	fmt++;
	if (*fmt == '*')
	{
		conv->prcsn = va_arg(ap, int);
		fmt++;
	}
	else
		conv->prcsn = ft_atoi(&fmt[0]);
	return (fmt);
}

const char	*ft_width(const char *fmt, va_list ap, t_conv *conv)
{
	if (*fmt == '*')
	{
		conv->width = va_arg(ap, int);
		if (conv->width < 0)
		{
			conv->flag = '-';
			conv->width *= -1;
		}
		fmt++;
	}
	else
		conv->width = ft_atoi(&fmt[0]);
	return (fmt);
}

const char	*ft_flag(const char *fmt, va_list ap, t_conv *conv)
{
	conv->flag = 0;
	while (*fmt == '0' || *fmt == '-')
	{
		if (*fmt == '0')
		{
			conv->flag = '0';
			fmt++;
			conv->width = ft_atoi(&fmt[0]);
		}
		if (*fmt == '-')
		{
			conv->flag = '-';
			while (*fmt == '0' || *fmt == '-')
				fmt++;
		}
	}
	fmt = ft_width(fmt, ap, conv);
	return (fmt);
}

const char	*percent(const char *fmt, va_list ap, int *len_ptr)
{
	t_conv	*conversion;

	conversion = malloc(sizeof(t_conv));
	if (!conversion)
		return (NULL);
	fmt++;
	fmt = ft_flag(fmt, ap, conversion);
	while (*fmt >= '0' && *fmt <= '9')
		fmt++;
	conversion->prcsn = -1;
	if (*fmt == '.')
	{
		fmt = ft_precision(fmt, ap, conversion);
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	fmt = type(fmt, ap, conversion, len_ptr);
	free(conversion);
	return (fmt);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt = percent(fmt, ap, &result);
			if (!fmt)
			{
				va_end(ap);
				return (-1);
			}
		}
		else
		{
			write(1, fmt, 1);
			result++;
			fmt++;
		}
	}
	va_end(ap);
	return (result);
}
