/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:37:44 by dle-fur           #+#    #+#             */
/*   Updated: 2024/10/18 16:03:54 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(int c, int *count) //pour afficher le % et %c
{
	(*count) += write(1, &c, 1);
}

void	print_s(char *str, int *count) //afficher le %s
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	else
	{
		while (str[i] != '\0')
		{
			(*count) += write(1, &str[i], 1);
			i++;
		}
	}
}

void	print_hex(long nb, int maj, int *count) //affiche le %x
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
		(*count) += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 16)
	{
		print_hex(nb / 16, maj, count);
		(*count) += write(1, &base[nb % 16], 1);
	}
	else
	{
		(*count) += write(1, &base[nb % 16], 1);
	}
}

void	print_n(long nb, int *count) //affiche %d et %i
{
	char	*base;

	base = "0123456789";
	if (nb < 0)
	{
		(*count) += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		print_n(nb / 10, count);
		(*count) += write(1, &base[nb % 10], 1);
	}
	else
	{
		(*count) += write(1, &base[nb % 10], 1);
	}
}

void	print_u(unsigned long nb, int *count) //afficher le %u only positif
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
	{
		print_u(nb / 10, count);
		(*count) += write(1, &base[nb % 10], 1);
	}
	else
	{
		(*count) += write(1, &base[nb % 10], 1);
	}
}

void	print_p(long nb, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		print_p(nb / 16, count);
		(*count) += write(1, &base[nb % 16], 1);
	}
	else
	{
		(*count) += write(1, "0x", 2);
		(*count) += write(1, &base[nb % 16], 1);
	}
}
