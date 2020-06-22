/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 11:46:34 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/02/02 11:42:42 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_long_ptr(char *s, int len, int *result)
{
	write(1, "0x", 2);
	write(1, s, len);
	*result += len + 2;
}

void	ft_no_flag_p(t_conv *conv, int len, char *s, int *result)
{
	int space;
	int zero;
	int width;
	int prcsn;

	space = 0;
	zero = 0;
	width = conv->width;
	prcsn = conv->prcsn;
	if (len > width && len > prcsn)
	{
		ft_long_ptr(s, len, result);
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

void	ft_zero_p(t_conv *conv, int len, char *s, int *result)
{
	int space;
	int zero;

	space = 0;
	zero = 0;
	if (len > conv->width && len > conv->prcsn)
	{
		ft_long_ptr(s, len, result);
		return ;
	}
	if (conv->prcsn > len)
		zero = conv->prcsn - len;
	if (conv->width > len && len > conv->prcsn)
	{
		if (conv->prcsn == -1)
			zero = conv->width - len - 2;
	}
	if (conv->prcsn != -1)
		space = (conv->prcsn > len) ?
			conv->width - conv->prcsn - 2 : conv->width - len - 2;
	ft_write(' ', space, result);
	write(1, "0x", 2);
	ft_write('0', zero, result);
	write(1, s, len);
	*result += len + 2;
}

void	ft_pointer(t_conv *conv, va_list ap, int *result)
{
	unsigned long	p;
	int				len;
	char			*s;
	char			*total;

	p = va_arg(ap, unsigned long);
	conv->type = 'p';
	len = ft_hexlen(p);
	s = ft_xtoa(p, len, conv->type);
	if (!s)
		return ;
	total = ft_strjoin("0x", s);
	if (conv->flag != '-' && conv->flag != '0')
		ft_no_flag_p(conv, len, s, result);
	if (conv->flag == '0')
		ft_zero_p(conv, len, s, result);
	if (conv->flag == '-')
		ft_dash_int(conv, len + 2, total, result);
	free(s);
	free(total);
}
