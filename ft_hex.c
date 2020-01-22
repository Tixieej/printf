/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:47:34 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/22 16:11:04 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

#include <stdio.h>
int			ft_hexlen(unsigned long x)
{
	int				len;
	unsigned long	nbr;

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

char		*ft_Xtoa(unsigned long x, int len)
{
	char			*str;
	int				temp;

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
			temp += 7;
		str[len] = temp + '0';
		x = x / 16;
		len--;
	}
	return (str);
}


char		*ft_xtoa(unsigned long x, int len)
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

void		ft_hex(char type, t_conv *conv, va_list ap, int *result)
{
	unsigned long	x;
	char			*s;
	int				width;
	int				prcsn;
	int				len;

	x = va_arg(ap, unsigned long);
	conv->type = 'x';
	if (type == 'X')
		conv->type = 'X';
	len = ft_hexlen(x);
	if (conv->type == 'x')
		s = ft_xtoa(x, len);
	else
		s = ft_Xtoa(x, len);
	width = conv->width;
	prcsn = conv->prcsn;
	if (prcsn == 0)
	{
		if (*s == '0')
		{
			free(s);//test %05.0 met 0, dat moet "     " geven?
			len = 0;
		}
	}
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag(width, prcsn, len, s, result);
	if (conv->flag == '0')
		ft_zero_int(conv, len, s, result);
	if (conv->flag == '-')
		ft_dash_int(width, prcsn, len, s, result);
}
