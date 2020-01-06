/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 09:30:29 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/06 11:21:38 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_conv
{
	char		flag;
	int			width;
	int			prcsn;
	char		type;
	int			arglen;
	char		padding;
}				t_conv;

void		ft_integer(const char *fmt, t_conv *conv, va_list ap);
const char	*ft_precision(const char *fmt, t_conv *conv);
void		ft_padding(t_conv *conv, int len);
const char	*ft_flag(const char *fmt, va_list ap, t_conv *conversion);
const char	*type(const char *fmt, va_list ap, t_conv *conversion);
const char	*percent(const char *fmt, va_list ap);
int			ft_printf(const char *fmt, ...);
void		ft_dash(int width, int prcsn, int len);
char		*ft_zero(int width, int prcsn, int len, char *s);
/*
** LIBFT functions 
*/
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *str);

#endif
