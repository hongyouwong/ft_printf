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
	if (num < 16)
	{
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
		{
			if (casing == 'x')
				ft_putchar_fd(num - 10 + 'a', 1);
			else if (casing == 'X')
				ft_putchar_fd(num - 10 + 'A', 1);
		}
	}
	else
	{
		ft_puthex(num / 16, casing);
		ft_puthex(num % 16, casing);
	}
}

int	ft_printhex(unsigned int num, const char casing)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, casing);
	return (ft_gethexlen(num));
}
