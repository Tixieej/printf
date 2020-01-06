/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 13:54:35 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/05 12:55:21 by rde-vrie      ########   odam.nl         */
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
			//write(1, &c, 1);
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
			conversion->padding = '0';
		//	printf("flag --> 0\n");
			fmt++;
			conversion->width = ft_atoi(&fmt[0]);
		}
		if (*fmt == '-')
		{
			conversion->flag = '-';
			conversion->padding = ' ';
		//	printf("flag --> -\n");
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
const char	*type(const char *fmt, va_list ap, t_conv *conversion)
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	//int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;//deze naam mag niet van norminette

	d = 0;	
	//printf("\ntype --> fmt is [%c]\n", *fmt);
	if (*fmt == 'c')
	{
		c = va_arg(ap, int);
		conversion->type = 'c';
		write(1, &c, 1);
	}
	else if (*fmt == 's')
	{
		s = va_arg(ap, char *);
		conversion->type = 's';
		write(1, s, ft_strlen(s));
	}
	else if (*fmt == 'p')
	{
		p = va_arg(ap, void *);
		write(1, "void ptr", 8);
	}
	else if (*fmt == 'i' || *fmt == 'd')
	{
		//i = va_arg(ap, int);
		//conversion->type = 'i';
		//s = ft_itoa(i);
		//conversion->arglen = ft_strlen(s);
		//ft_padding(conversion, ft_strlen(s));
		ft_integer(fmt, conversion, ap);
		//write(1, s, ft_strlen(s));
	}
	else if (*fmt == 'u')
	{
		u = va_arg(ap, unsigned int);
		write(1, "uint", 4);
	}
	else if (*fmt == 'x')
	{
		x = va_arg(ap, unsigned int);
		write(1, "hexadec", 7);
	}
	else if (*fmt == 'X')
	{
		X = va_arg(ap, unsigned int);
		write(1, "HEX", 3);
	}	
	else if (*fmt == '%')
		write(1, "%", 1);
	fmt++;
	//printf("\ntype --> fmt is [%c]\n", *fmt);
	return (fmt);
}

const char	*percent(const char *fmt, va_list ap)
{
	t_conv	*conversion;

	conversion = malloc(sizeof(t_conv));
	if (!conversion)
		return ("error!");
	//printf("\npercent --> fmt is [%c]\n", *fmt);
	fmt++;
	/* flags: 0 - */
	fmt = ft_flag(fmt, ap, conversion);
	/* * = width = min no of char to output */
	while (*fmt >= '0' && *fmt <= '9')
		fmt++;
	/* . = precision = max no of char to output*/
	conversion->prcsn = 0;
	if (*fmt == '.')
	{
		fmt = ft_precision(fmt, conversion);
		//printf("\npercent --> len of prcsn is [%i]\n", (int)ft_strlen(ft_itoa(conversion->prcsn)));
		fmt += (int)ft_strlen(ft_itoa(conversion->prcsn));
		//als 0 en . dan wil je spaties ipv de nullen
		if (conversion->flag == '0')
			conversion->padding = ' ';
		/* er komt nu een getal of een *  */
	}
	/* cspdiuxX% */
	fmt = type(fmt, ap, conversion);
	//printf("\nconversion is gevuld met flag=%c, width=%i, precision=%i, type=%c\n",
		   //	conversion->flag, conversion->width, conversion->prcsn, conversion->type);
	return (fmt);
}

/* fmt is de string, altijd het eerste argument van printf */
/* ... staat voor alle andere argumenten, die bij de flags in fmt horen */
int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	rest;
	
	va_start(ap, fmt);
	while (*fmt)
	{
		/* als % voorkomt in fmt, moet je kijken wat erna komt */
		/* sla alles voor de placeholder/type op in een struct */
		if (*fmt == '%')
			fmt = percent(fmt, ap);
		else
		{
			/*print gewoon de string*/
			rest = *fmt;
			write(1, &rest, 1);
			fmt++;
		}
		va_end(ap);
	}
	return (0);
}
