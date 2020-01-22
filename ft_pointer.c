/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:28:55 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/22 13:13:00 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

void	ft_no_flag_p(int width, int prcsn, int len, char *s, int *result)
{
	int space;
	int zero;

	space = 0;
	zero = 0;
	if (len > width && len > prcsn)
	{
		write(1, "0x", 2);
		write(1, s, len);
		*result += len + 2;
		return ;
	}
	if (prcsn > len)
		zero = prcsn - len;
	space = (prcsn > len) ? width - prcsn - 2 : width - len - 2;
	ft_write(' ', space, result);
	write(1, "0x", 2);
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len + 2;
}

void	ft_zero_p(int width, int prcsn, char *s, int *result)
{
	int space;
	int zero;

	space = 0;
	zero = 0;
	if (12 > width && 12 > prcsn)
	{
		write(1, "0x", 2);
		write(1, s, 12);
		*result += 14;
		return ;
	}
	if (prcsn > 12)
		zero = prcsn - 12;
	if (width > 12 && 12 > prcsn)
	{
		if (prcsn == -1)
			zero = width - 14;
		else
			space = width - 14;//deze kan weg? want hieronder
	}
	if (prcsn != -1)
		space = (prcsn > 12) ? width - prcsn - 2 : width - 14;
	ft_write(' ', space, result);
	write(1, "0x", 2);
	ft_write('0', zero, result);
	write(1, s, 12);
	*result += 14;
}

void	ft_pointer(t_conv *conv, va_list ap, int *result)
{
	unsigned long	p;
	int				width;
	int				prcsn;
	int				len;
	char			*s;
	char			*total;

	p = va_arg(ap, unsigned long);
	conv->type = 'p';
	width = conv->width;
	prcsn = conv->prcsn;
	len = ft_hexlen(p);
	s = ft_xtoa(p, len);
	total = ft_strjoin("0x", s);
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag_p(width, prcsn, len, s, result);
	if (conv->flag == '0')
		ft_zero_p(width, prcsn, s, result);
	if (conv->flag == '-')
		ft_dash_int(width, prcsn, len + 2, total, result);
}
