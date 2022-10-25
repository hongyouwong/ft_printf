/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:43:20 by hwong             #+#    #+#             */
/*   Updated: 2022/10/15 22:43:20 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_gethexlen(uintptr_t hex)
{
	int	count;

	count = 0;
	while (hex != 0)
	{
		hex /= 16;
		count++;
	}
	return (count);
}

void	ft_puthex(unsigned int num, const char casing)
{
	if (num >= 16)
		ft_puthex(num / 16, casing);
	if (casing == 'x')
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
	else if (casing == 'X')
		ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
}

int	ft_printhex(unsigned int num, const char casing)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, casing);
	return (ft_gethexlen(num));
}
