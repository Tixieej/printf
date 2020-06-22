/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   integer2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 11:40:07 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/02/02 11:42:13 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_write(char c, int len, int *result)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
		(*result)++;
	}
}
