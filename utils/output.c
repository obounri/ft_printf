/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:28:15 by obounri           #+#    #+#             */
/*   Updated: 2020/02/26 19:11:46 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print_c(t_format *data, int *printed)
{
	if ((*data).w >= 1)
		(*data).w -= 1;
	while (((*data).flag == -1) && (--(*data).w >= 0) && ++*printed)
		write(1, " ", 1);
	while (((*data).flag == '0') && (--(*data).w >= 0) && ++*printed)
		write(1, "0", 1);
	ft_putchar_fd((*data).c, 1);
	*printed += 1;
	if (((*data).flag == '-') && ((*data).w > 0))
		while ((--(*data).w >= 0) && ++*printed)
			write(1, " ", 1);
}

static void		print_pourcentage(t_format *data, int *printed)
{
	if ((*data).w >= 1)
		(*data).w -= 1;
	while (((*data).flag == -1) && (--(*data).w >= 0) &&
			++*printed)
		write(1, " ", 1);
	while (((*data).flag == '0') && (--(*data).w >= 0) &&
			++*printed)
		write(1, "0", 1);
	ft_putstr_fd((*data).content, 1);
	*printed += 1;
	if (((*data).flag == '-') && ((*data).w > 0))
		while ((--(*data).w >= 0) && ++*printed)
			write(1, " ", 1);
}

static void		str_toupper(char *content)
{
	int i;

	i = 0;
	while (content[i] != '\0')
	{
		if ((content[i] >= 97) && (content[i] <= 122))
			content[i] -= 32;
		i++;
	}
}

void			output(t_format *data, int *printed, int len_content)
{
	if ((*data).cs == 'd' || (*data).cs == 'i' || (*data).cs == 'u')
	{
		if ((*data).content[0] == '-')
			(*data).negatif_int = 1;
		print_intp(data, len_content, printed);
	}
	else if ((*data).cs == 'x' || (*data).cs == 'X')
	{
		if ((*data).cs == 'X')
			str_toupper((*data).content);
		print_intp(data, len_content, printed);
	}
	else if ((*data).cs == 'p')
		print_intp(data, len_content, printed);
	else if ((*data).cs == 's')
		print_s(data, len_content, printed);
	else if ((*data).cs == 'c')
		print_c(data, printed);
	else if ((*data).cs == '%')
		print_pourcentage(data, printed);
}
