/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:47:34 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/14 15:57:11 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

#include <stdio.h>
static int	ft_hexlen(unsigned int x)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (x == 0)
		return (1);
	nbr = x;
	while (nbr >= 1)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

char		*ft_itoa_hex(unsigned int x, int len)
{
	char			*str;
	//int				len;
	int				temp;

	//len = ft_hexlen(x);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (x == 0)
		str[0] = '0';
	while (x > 0)
	{
		temp = (x % 16);
		if (temp > 9)
			temp += 39;
		str[len] = temp + '0';
		x = x / 16;
		len--;
	}
	return (str);
}

void		ft_hex(const char *fmt, t_conv *conv, va_list ap)
{
	unsigned int	x;
	char			*s;
	int				width;
	int				prcsn;
	int				len;

	x = va_arg(ap, unsigned int);
	(void)fmt;
	conv->type = 'x';
	len = ft_hexlen(x);
	s = ft_itoa_hex(x, len);
	width = conv->width;
	prcsn = conv->prcsn;
	//len = ft_strlen(s);
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag(width, prcsn, len, s);
	if (conv->flag == '0')
		ft_zero_int(width, prcsn, len, s);
	if (conv->flag == '-')
		ft_dash_int(width, prcsn, len, s);
	/*if (width != 0)
	{
		if (conv->flag == '0')
			ft_zeroes(width, prcsn, len);
	}
	//write(1, s, len);
	if (conv->flag == '-')
		ft_spaces(width, prcsn, len);*/
}
