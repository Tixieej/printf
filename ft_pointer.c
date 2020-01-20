/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:28:55 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/20 16:38:34 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

void	ft_zero_p(int width, int prcsn, int len, char *s, int *result)
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
	if (width > len && len > prcsn)
	{
		if (prcsn == -1)
			zero = width - len;
		else
			space = width - len;
	}
	if (prcsn != -1)
		space = (prcsn > len) ? width - prcsn : width - len;
	ft_write(' ', space, result);
	write(1, "0x", 2);
	ft_write('0', zero, result);
	write(1, s, len-2);
	*result += len;
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
	len += 2;
	total = ft_strjoin("0x", s);
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag(width, prcsn, len, total, result);
	if (conv->flag == '0')
		ft_zero_p(width, prcsn, len, s, result);
	if (conv->flag == '-')
		ft_dash_int(width, prcsn, len, total, result);
}
