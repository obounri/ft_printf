/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:13:06 by obounri           #+#    #+#             */
/*   Updated: 2020/02/27 15:47:52 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*c_to_s(char c)
{
	char *str;

	str = (char *)malloc(1);
	str[0] = c;
	return (str);
}

static void		check_error(va_list *arg, t_format *data)
{
	(*data).content = ft_strdup(va_arg(*arg, char *));
	if (!(*data).content)
		(*data).content = ft_strdup("(null)");
}

void			fill_content(t_format *data, va_list *arg, int *len_content)
{
	if ((*data).cs == 'd' || (*data).cs == 'i')
		(*data).content = ft_itoa(va_arg(*arg, int));
	else if ((*data).cs == 'u')
		(*data).content = ft_itoa_unsigned(va_arg(*arg, unsigned int));
	else if ((*data).cs == 'x' || (*data).cs == 'X')
		(*data).content = ft_itoa_hexa(va_arg(*arg, unsigned int));
	else if ((*data).cs == 'p')
		(*data).content = ft_itoa_hexa(va_arg(*arg, unsigned long int));
	else if ((*data).cs == 'c')
		(*data).c = va_arg(*arg, int);
	else if ((*data).cs == 's')
		check_error(arg, data);
	else if ((*data).cs == '%')
		(*data).content = c_to_s('%');
	if ((*data).cs == 'c')
		*len_content = 1;
	else
		*len_content = ft_strlen((*data).content);
}
