/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:50:56 by hwong             #+#    #+#             */
/*   Updated: 2022/10/17 16:40:25 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(str);
	dst = (char *) malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	ft_memmove(dst, str, size);
	dst[size] = '\0';
	return (dst);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!dst && !src)
		return (0);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (dst < src)
		while (n-- > 0)
			*(ptr_dst++) = *(ptr_src++);
	else
	{
		ptr_dst += n;
		ptr_src += n;
		while (n-- > 0)
			*(--ptr_dst) = *(--ptr_src);
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
