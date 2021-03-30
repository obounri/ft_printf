/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 00:44:15 by obounri           #+#    #+#             */
/*   Updated: 2020/02/27 16:29:19 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		init(t_format *data)
{
	(*data).cs = 'x';
	(*data).lf = 0;
	(*data).flag = -1;
	(*data).w = -1;
	(*data).p = -1;
	(*data).negatif_int = -1;
	(*data).c = 'x';
	(*data).content = NULL;
	(*data).print_minus = -1;
}

static int		detect_flag(char *str, t_format *data)
{
	if (str[(*data).lf] == '\0')
		return (-1);
	else if (((str[(*data).lf] == '0') &&
		(str[(*data).lf + 1] == '-')) ||
		((str[(*data).lf] == '-') &&
		(str[(*data).lf + 1] == '0')))
	{
		(*data).flag = '-';
		(*data).lf += 2;
		return (1);
	}
	else if (str[(*data).lf] == '-')
	{
		(*data).flag = '-';
		(*data).lf++;
		return (1);
	}
	else if (str[(*data).lf] == '0')
	{
		(*data).flag = '0';
		(*data).lf++;
		return (1);
	}
	return (0);
}

static int		detect_width(char *str, va_list *arg, t_format *data)
{
	if (str[(*data).lf] == '\0')
		return (-1);
	else if (str[(*data).lf] == '*')
	{
		if (((*data).w = va_arg(*arg, int)) < 0)
		{
			(*data).flag = '-';
			(*data).w *= -1;
		}
		(*data).lf++;
		return (1);
	}
	while (str[(*data).lf] == '-' &&
			str[(*data).lf] != '\0')
		(*data).lf++;
	(*data).w = ft_atoi(&str[(*data).lf]);
	while (ft_isdigit(str[(*data).lf]) &&
			str[(*data).lf] != '\0')
		(*data).lf++;
	if (str[(*data).lf] == '\0')
		return (-1);
	else
		return (1);
}

static int		detect_precision(char *str, va_list *arg, t_format *data)
{
	if (str[(*data).lf] == '\0')
		return (-1);
	else if (str[(*data).lf] != '.')
		return (0);
	(*data).lf++;
	if (str[(*data).lf] == '*')
	{
		(*data).p = va_arg(*arg, int);
		(*data).lf++;
		return (1);
	}
	else if (str[(*data).lf] == '\0')
		return (-1);
	(*data).p = 0;
	while (str[(*data).lf] == '0' && str[(*data).lf] != '\0')
		(*data).lf++;
	if (str[(*data).lf] == '\0')
		return (-1);
	(*data).p = ft_atoi(&str[(*data).lf]);
	while (ft_isdigit(str[(*data).lf]) && str[(*data).lf] != '\0')
		(*data).lf++;
	if (str[(*data).lf] == '\0')
		return (-1);
	return (0);
}

int				detect_format(char *str, va_list *arg, t_format *data)
{
	init(data);
	if ((detect_flag(str, data)) == -1)
		return (-1);
	if ((detect_width(str, arg, data)) == -1)
		return (-1);
	if ((detect_precision(str, arg, data)) == -1)
		return (-1);
	(*data).cs = str[(*data).lf];
	(*data).lf++;
	return (1);
}
