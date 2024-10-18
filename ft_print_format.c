/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:37:44 by dle-fur           #+#    #+#             */
/*   Updated: 2024/10/18 11:47:35 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c) //pour afficher le % et %c
{
	write(1, &c, 1);
	return (1);
}

int	print_s(char *str) //afficher le %s
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

void	print_hex(long nb, int maj)
{
	char	*base;

	if (maj == 1)
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 16)
	{
		print_hex(nb / 16, maj);
		write(1, &base[nb % 16], 1);
	}
	else
	{
		write(1, &base[nb % 16], 1);
	}
}
