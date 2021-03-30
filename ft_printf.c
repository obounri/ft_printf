/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:03:28 by obounri           #+#    #+#             */
/*   Updated: 2020/02/27 15:59:07 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		printed;
	char	*fermat;
	va_list	arg;

	va_start(arg, format);
	printed = 0;
	fermat = (char *)format;
	while (*fermat != '\0')
	{
		if ((*fermat != '%') && ++printed)
			write(1, &(*fermat), 1);
		else if (++fermat && (*fermat == '%') && ++printed)
			write(1, "%", 1);
		else if (*fermat == '\0')
			continue ;
		else
		{
			fermat += manage_format(fermat, &arg, &printed);
			continue ;
		}
		fermat++;
	}
	va_end(arg);
	return (printed);
}
