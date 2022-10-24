/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:08:18 by hwong             #+#    #+#             */
/*   Updated: 2022/10/10 15:08:18 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_itoa(n);
	len = ft_printstr(nbr);
	free(nbr);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_uitoa(n);
	len = ft_printstr(nbr);
	free(nbr);
	return (len);
}
