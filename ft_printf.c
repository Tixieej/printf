/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 13:54:35 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/22 15:45:13 by rde-vrie      ########   odam.nl         */
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
	//printf("\nflag --> prcsn is [%i]\n", conv->prcsn);
	return (fmt);
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

const char	*type(const char *fmt, va_list ap, t_conv *conversion, int *result)
{
//	void *test;

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
//	else
//	{
	//	test = malloc(sizeof(char) * (unsigned long)NULL);
	//	if (!test)
	//		return ;
	//	printf(" Type adres = %p ", test); 
//	}	
	fmt++;
	return (fmt);
}

const char	*percent(const char *fmt, va_list ap, int *len_ptr)
{
	t_conv	*conversion;

	conversion = malloc(sizeof(t_conv));
//	printf(" Percent adres = %p ", conversion); 
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
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	fmt = type(fmt, ap, conversion, len_ptr);
//	printf(" Percent conv width = %p, prcsn = %p ", &(conversion->width), &(conversion->prcsn));
	free(conversion);
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
			rest = *fmt;
			write(1, &rest, 1);
			result++;
			fmt++;
		}
		va_end(ap);
	}
	return (result);
}
