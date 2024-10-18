/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:27:52 by dle-fur           #+#    #+#             */
/*   Updated: 2024/10/18 15:56:13 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
//utils//
void	print_s(char *str, int *count);
void	print_c(int c, int *count);
void	print_hex(long nb, int maj, int *count);
void	print_n(long nb, int *count);
void	print_u(unsigned long n, int *count);
void	print_p(long nb, int *count);
void	print_p(long nb, int *count);

#endif