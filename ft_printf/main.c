/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabidi <yabidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:55:32 by yabidi            #+#    #+#             */
/*   Updated: 2022/11/03 08:55:22 by yabidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(char s )
{
	if (s == 'i' || s == 'c' || s == 's' || s == 'p'
		|| s == 'd' || s == 'u' || s == 'x' || s == 'X')
		return (s);
	return (0);
}

static int	c_puts2(int conv, va_list lst)
{
	int	len;

	len = 0;
	if (conv == 'p')
	{
		len += ft_putstr_fd("0x", 1);
		len += ft_putnbr_base2(va_arg(lst, unsigned long));
	}
	if (conv == 'd' || conv == 'i')
		len += ft_putnbr_fd(va_arg(lst, int), 1);
	if (conv == 'u' )
		len += ft_putnbr_fd(va_arg(lst, unsigned int), 1);
	if (conv == 'x')
		len += ft_putnbr_base(va_arg(lst, int));
	if (conv == 'X')
		len += ft_putnbr_base3(va_arg(lst, int));
	return (len);
}

static int	c_puts(int conv, va_list lst, int *i)
{
	char	*s;
	int		len;

	len = 0;
	if (conv == 'c' )
		len += ft_putchar_fd(va_arg(lst, int), 1);
	if (conv == 's')
	{
		s = va_arg(lst, char *);
		if (!s)
			len += ft_putstr_fd("(null)", 1);
		else
			len += ft_putstr_fd(s, 1);
	}
	len += c_puts2(conv, lst);
	*i += 2;
	return (len);
}

static int	check_put(const char *s, int *len, int *i)
{
	while ((s + *i))
	{
		if (s[*i] == '%' && check(*(s + *i + 1)))
			return (check(*(s + *i + 1)));
		if (s[*i] == '%')
			(*i)++;
		if (!s[*i])
			return (0);
		ft_putchar_fd(s[*i], 1);
		*len += 1;
		(*i)++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		conv;
	int		len;
	va_list	lst;
	int		i;

	va_start(lst, s);
	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (1)
	{
		conv = check_put(s, &len, &i);
		if (conv == 0)
			return (va_end(lst), len);
		len += c_puts(conv, lst, &i);
	}
}
