/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:44:59 by hwong             #+#    #+#             */
/*   Updated: 2022/10/17 09:44:59 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(int c);
void	ft_putchar_fd(char c, int fd);
int		ft_printpercent(void);
int		ft_printstr(char *str);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
char	*ft_itoa(int n);
int		count_char_u(unsigned int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strdup(const char *str);
void	ft_putptr(uintptr_t num);
int		ft_printptr(uintptr_t ptr);
int		ft_gethexlen(uintptr_t hex);
void	ft_puthex(unsigned int num, const char casing);
int		ft_printhex(unsigned int num, const char casing);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);

int		ft_printf(const char *str, ...);

#endif