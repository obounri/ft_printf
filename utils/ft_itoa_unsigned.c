/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:22:54 by obounri           #+#    #+#             */
/*   Updated: 2020/02/24 16:16:50 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_len(unsigned int n)
{
	unsigned int	tmp;
	int				size;

	tmp = n;
	size = 0;
	while (tmp > 0)
	{
		size++;
		tmp = tmp / 10;
	}
	return (size);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char	*ptr;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_len(n);
	if (!(ptr = (char*)malloc(size + 1)))
		return (0);
	ptr[size] = '\0';
	while (n > 0 && size >= 0)
	{
		ptr[--size] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}
