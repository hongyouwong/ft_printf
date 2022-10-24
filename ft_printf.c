/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:43:24 by hwong             #+#    #+#             */
/*   Updated: 2022/10/15 22:43:24 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsetype(va_list args, const char c)
{
	int	printed_len;

	printed_len = 0;
	if (c == 'c')
		printed_len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		printed_len += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		printed_len += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		printed_len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		printed_len += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		printed_len += ft_printhex(va_arg(args, unsigned int), c);
	else if (c == '%')
		printed_len += ft_printpercent();
	return (printed_len);
}

int	ft_printf(const char *str, ...)
{
	int		printed_len;
	va_list	args;

	printed_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{	
			printed_len += ft_parsetype(args, *(str + 1));
			str++;
		}
		else
			printed_len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (printed_len);
}
