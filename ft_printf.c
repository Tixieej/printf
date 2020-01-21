/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 13:54:35 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/21 11:59:41 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>
const char	*ft_precision(const char *fmt, t_conv *conv)
{
	fmt++;
	conv->prcsn = ft_atoi(&fmt[0]);
	return (fmt);
}

void		ft_padding(t_conv *conv, int len)
{//Deze functie kan misschien weg of iig korter, want werkt alleen voor 0 niet mmeer voor -
	int		total;
	char	c;

	total = conv->width;
	total -= len;
	if (conv->flag == '0')
	{
		c = conv->padding;
		while (total > 0)
		{
			total--;
		}
	}
}

const char	*ft_flag(const char *fmt, va_list ap, t_conv *conversion)
{
	while (*fmt == '0' || *fmt == '-')
	{
		if (*fmt == '0')
		{
			conversion->flag = '0';
		//	conversion->padding = '0';
			fmt++;
			conversion->width = ft_atoi(&fmt[0]);
		}
		if (*fmt == '-')
		{
			conversion->flag = '-';
		//	conversion->padding = ' ';
			while (*fmt == '0' || *fmt == '-')
				fmt++;
		}
	}
	if (*fmt == '*')
	{
		conversion->width = va_arg(ap, int);
		fmt++;
	}
	else
		conversion->width = ft_atoi(&fmt[0]);
	//printf("\nflag --> width is [%i]\n", conversion->width);
	return (fmt);
}

/* functie die flags krijgt en afhandelt hij krijgt % binnen */
/* hier moet een deel van wat je in printf hebt naartoe */
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

const char	*percent(const char *fmt, va_list ap, int *len_ptr)
{
	t_conv	*conversion;

	conversion = malloc(sizeof(t_conv));
	if (!conversion)
		return ("error!");
	fmt++;
	fmt = ft_flag(fmt, ap, conversion);
	while (*fmt >= '0' && *fmt <= '9')
		fmt++;
	conversion->prcsn = -1;
	if (*fmt == '.')
	{
		fmt = ft_precision(fmt, conversion);
		fmt += (int)ft_strlen(ft_itoa(conversion->prcsn));
	}
	fmt = type(fmt, ap, conversion, len_ptr);
	return (fmt);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	rest;
	int		result;

	result = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			fmt = percent(fmt, ap, &result);
		else
		{
			/*print gewoon de string*/
			rest = *fmt;
			write(1, &rest, 1);
			result++;
			fmt++;
		}
		va_end(ap);
	}
	return (result);// hier moet de lengte van wat je hebt geprint komen
}
