/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 12:58:00 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/20 12:31:30 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <unistd.h>

#include <stdio.h> //WEHEGALElolll
void	ft_write_string(int prcsn, int len, char *s, int *result)
{
	int j;

	j = len;
	if (prcsn != -1)
		j = (prcsn < len) ? prcsn : len;
	write(1, s, j);
	*result += j;
}

void	ft_zeroes(int width, int prcsn, int len, int *result)
{
	int min;

	if (prcsn != -1)
		min = (prcsn < len) ? prcsn : len;
	else
		min = len;
	while (width - min > 0)
	{
		write(1, "0", 1);
		(*result)++;
		min++;
	}
}
void	ft_spaces(int width, int prcsn, int len, int *result)
{
	int min;

	if (prcsn != -1)
		min = (prcsn < len) ? prcsn : len;
	else
		min = len;
	while (width - min > 0)
	{
		write(1, " ", 1);
		(*result)++;
		min++;
	}
}

void	ft_string(t_conv *conv, va_list ap, int *result)
{
	char	*s;
	int		width;
	int		len;
	int		prcsn;

	s = va_arg(ap, char*);
	conv->type = 's';
	width = conv->width;
	prcsn = conv->prcsn;
	len = ft_strlen(s);
	if (width != 0)
	{
		if (conv->flag != '-' && conv->flag != '0')
			ft_spaces(width, prcsn, len, result);
		if (conv->flag == '0')
			ft_zeroes(width, prcsn, len, result);
	}
	ft_write_string(prcsn, len, s, result);
	if (conv->flag == '-')
		ft_spaces(width, prcsn, len, result);
}
