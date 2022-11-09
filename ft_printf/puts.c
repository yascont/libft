/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabidi <yabidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:55:36 by yabidi            #+#    #+#             */
/*   Updated: 2022/11/03 08:55:45 by yabidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		write(fd, s++, 1);
		len++;
	}
	return (len);
}

int	ft_putnbr_fd(long long int n, int fd)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
	{
		len += ft_putnbr_fd(n / 10, fd);
	}
	len += ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}
