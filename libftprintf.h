/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 09:30:29 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/22 13:20:21 by rde-vrie      ########   odam.nl         */
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
}				t_conv;

void		ft_integer(t_conv *conv, va_list ap, int *result);
const char	*ft_precision(const char *fmt, t_conv *conv);
void		ft_padding(t_conv *conv, int len);
const char	*ft_flag(const char *fmt, va_list ap, t_conv *conversion);
const char	*type(const char *fmt, va_list ap, t_conv *conversion, int *result);
const char	*percent(const char *fmt, va_list ap, int *result);
int			ft_printf(const char *fmt, ...);
void		ft_dash(int width, int prcsn, int len);
char		*ft_zero(int width, int prcsn, int len, char *s);
void		ft_string(t_conv *conv, va_list ap, int *result);
void		ft_spaces(int width, int prcsn, int len, int *result);
void		ft_zeroes(int width, int prcsn, int len, int *result);
void		ft_write_string(int prcsn, int len, char *s, int *result);
void		ft_char(const char fmt, t_conv *conv, va_list ap, int *result);
void		ft_pointer(t_conv *conv, va_list ap, int *result);
void		ft_hex(char type, t_conv *conv, va_list ap, int *result);
int			ft_hexlen(unsigned long x);
char		*ft_xtoa(unsigned long x, int len);
char		*ft_Xtoa(unsigned long x, int len);
void		ft_zero_int(t_conv *conv, int len, char *s, int *result);
void		ft_no_flag(int width, int prcsn, int len, char *s, int *result);
void		ft_dash_int(int width, int prcsn, int len, char *s, int *result);
void		ft_uint(t_conv *conv, va_list ap, int *result);
void		ft_no_flag_p(int width, int prcsn, int len, char *s, int *result);
void		ft_zero_p(int width, int prcsn, char *s, int *result);
void		ft_write(char c, int len, int *result);
/*
** LIBFT functions 
*/
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
