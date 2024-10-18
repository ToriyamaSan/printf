/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:46:40 by dle-fur           #+#    #+#             */
/*   Updated: 2024/10/18 12:01:13 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
exemple : ft_printf("je m appelle &s et j ai &d ans", "david", 23);
index = 0 : parcour la phrase donnee en parametre
count = 0 : parcour la phrase output, dans l'exemple
count parcour : je m appelle david et j ai 23 ans


va_list args = l argument principale obligatoire qui est la phrase
va_arg va permettre d acceder a l argument %s et ensuite le %d

va_list args = liste argument
format = char, int etc
ce qui sort sur la console et une chaine de caractere ou un caractere
et se finit par '\0'
va_arg = macro qui permet d afficher l argument en parametre
va_start = permet d initialiser la liste des variable
va_end = permet d arreter l utilisation des variables
*/

#include "ft_printf.h"

static void	check_format(va_list args, const char format)
{
	if (format == '%')
	{
		print_c('%');
	}
	else if (format == 'c')
	{
		print_c(va_arg(args, int));
	}
	else if (format == 's')
	{
		print_s(va_arg(args, char *));
	}
	else if (format == 'x')
	{
		print_hex(va_arg(args, long), 0);
	}
	else if (format == 'X')
	{
		print_hex(va_arg(args, long), 1);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;
				check_format(args, format[i]);
			}
			else if (format[i] != '%')
			{
				print_c(format[i]);
			}
			i++;
		}
	}
	va_end(args);
	return (0);
}
int	main(void)
{
	long	nb;
	int		count;

	nb = -255;
	count = ft_printf("l'hexa est %x dsddsd\n", nb);
	printf("%d\n", count);
	return (0);
}
