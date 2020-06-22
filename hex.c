/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 11:45:04 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/02/02 11:43:53 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

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

char		*ft_xtoa(unsigned long x, int len, char type)
{
	char			*str;
	int				temp;
	int				upp;

	upp = 0;
	if (type == 'X')
		upp = 32;
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
			temp += 39 - upp;
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
	int				len;

	x = (unsigned long)va_arg(ap, unsigned int);
	conv->type = type;
	len = ft_hexlen(x);
	s = ft_xtoa(x, len, conv->type);
	if (!s)
		return ;
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
