/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uint.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 11:44:42 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/02/02 11:42:03 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int		ft_ulen(unsigned int u)
{
	int		len;

	len = 0;
	if (u == 0)
		return (1);
	while (u > 0)
	{
		u = u / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int u, int len)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	len--;
	if (u == 0)
		s[0] = '0';
	while (u > 0)
	{
		s[len] = (u % 10) + '0';
		u = u / 10;
		len--;
	}
	return (s);
}

void	ft_uint(t_conv *conv, va_list ap, int *result)
{
	unsigned int	u;
	char			*s;
	int				len;

	u = va_arg(ap, unsigned int);
	conv->type = 'u';
	len = ft_ulen(u);
	s = ft_utoa(u, len);
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
