/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:32:40 by hwong             #+#    #+#             */
/*   Updated: 2022/10/11 22:32:40 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(uintptr_t num)
{
	if (num <= 16)
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
	else
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
}

int	ft_printptr(uintptr_t ptr)
{
	int	printed_len;

	printed_len = 0;
	printed_len += write(1, "0x", 2);
	if (ptr == 0)
		printed_len += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		printed_len += ft_gethexlen(ptr);
	}
	return (printed_len);
}
