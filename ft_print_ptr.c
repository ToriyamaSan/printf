/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:10:39 by dle-fur           #+#    #+#             */
/*   Updated: 2024/10/20 15:12:05 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(uintptr_t ptr, int *count) //afficher adresse pointeur
{
	char	*base;

	base = "0123456789abcdef";
	(*count) += write(1, "0x", 2);
	if (ptr == 0)
	{
		(*count) += write(1, "0", 1);
		return ;
	}
	if (ptr >= 16)
	{
		print_p(ptr / 16, count);
		(*count) += write(1, &base[ptr % 16], 1);
	}
	else
	{
		if (ptr <= 9)
		{
			print_c(ptr + 48, count);
		}
		else
		{
			print_c(ptr - 10 + 'a', count);
		}
	}
}
