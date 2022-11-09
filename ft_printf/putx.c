/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabidi <yabidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:52:04 by yabidi            #+#    #+#             */
/*   Updated: 2022/11/03 08:54:31 by yabidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base2(unsigned long ptr)
{
	unsigned long	nb;
	int				len;

	len = 0;
	nb = (unsigned long)ptr;
	if (nb <= 15)
		len += ft_putchar_fd("0123456789abcdef"[nb], 1);
	else
	{	
		len += ft_putnbr_base2(nb / 16);
		len += ft_putnbr_base2(nb % 16);
	}
	return (len);
}

int	ft_putnbr_base3(unsigned int ptr)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = (unsigned int)ptr;
	if (nb <= 15)
		len += ft_putchar_fd("0123456789ABCDEF"[nb], 1);
	else
	{	
		len += ft_putnbr_base3(nb / 16);
		len += ft_putnbr_base3(nb % 16);
	}
	return (len);
}

int	ft_putnbr_base(unsigned int ptr)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = (unsigned int)ptr;
	if (nb <= 15)
		len += ft_putchar_fd("0123456789abcdef"[nb], 1);
	else
	{	
		len += ft_putnbr_base(nb / 16);
		len += ft_putnbr_base(nb % 16);
	}
	return (len);
}
