/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:23:05 by obounri           #+#    #+#             */
/*   Updated: 2020/02/24 17:22:43 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		len_n(unsigned long int n)
{
	int size;

	size = 0;
	while (n > 0)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

char	*ft_itoa_hexa(unsigned long int n)
{
	char	*base;
	char	*str;
	int		i;

	i = len_n(n);
	base = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (n > 0)
	{
		str[--i] = base[n % 16];
		n /= 16;
	}
	return (str);
}
