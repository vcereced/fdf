/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:50 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/27 22:07:23 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

static int	get_num(char c, int int_base, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && i < int_base)
		i++;
	return (i);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;
	int	num;

	result = 0;
	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str == '0' || *str == 'x')
		str++;
	while (*str)
	{
		num = get_num(to_lower(*str), str_base, "0123456789abcdef");
		result = num + (result * str_base);
		str++;
	}
	result *= sign;
	return (result);
}
