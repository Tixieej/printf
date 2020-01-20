/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_integer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 16:34:35 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/16 09:37:45 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

#include <stdio.h> //WEGHAELENE LOL

void	ft_dash(int width, int prcsn, int len)
{
	len = (len > prcsn) ? len : prcsn;
	while (width > len)
	{
		write(1, " ", 1);
		width--;
	}
}

char	*ft_zero(int width, int prcsn, int len, char *s)
{
	char	padding;
	//als je 0x en .y hebt dan krijg je x-y  aan spaties en y aan 0+getal
		padding = '0';
		if (prcsn > 0 && width > prcsn)
			padding = ' ';
		else if (*s == '-')
		{
			write(1, s, 1);
			len--;
			width--;
			s++;
		}
		width = (width > prcsn) ? width : prcsn;
		while (width > len)
		{
			write(1, &padding, 1);
			width--;
		}
		return (s);
}

void	ft_integer(const char *fmt, t_conv *conv, va_list ap)
{
	int		i;
	int		width;
	int		len;
	char	*s;
	int		prcsn;
	int		j;

	(void)fmt;   // WEHGHAEN LLOL ok dank mark
	i = va_arg(ap, int);
	conv->type = 'i';
	s = ft_itoa(i);
	//conv->arglen = ft_strlen(s);
	//ft_padding(conv, ft_strlen(s));
	width = conv->width;
	//len = conv->arglen;
	prcsn = conv->prcsn;
	len = ft_strlen(s);
	if (conv->flag == '0') //|| prcsn > 0
		s = ft_zero(width, prcsn, len, s);
	else
	{
		if (prcsn > 0)
		{
			if (conv->flag != '-')
			{
				if (*s == '-')
					width--;
				while (width > prcsn)
				{
					write(1, " ", 1);
					width--;
				}
			}
			j = prcsn - len;
			while (j > 0)
			{
				if (*s == '-')
				{
					write(1, s, 1);
					width--;
					len--;
					j++;
					s++;
				}
				write(1, "0", 1);
				j--;
			}
		}
		else if (conv->flag != '-')
		{
			while (width > len)
			{
				write(1, " ", 1);
				width--;
			}
		}
	}
	//print integer
	write(1, s, len);
	//als flag == -, print de spaties
	if(conv->flag == '-')
		ft_dash(width, prcsn, len);
}
