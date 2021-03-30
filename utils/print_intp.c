/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:01:15 by obounri           #+#    #+#             */
/*   Updated: 2020/02/26 20:05:35 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		f_w(t_format *data, int len_content, int *printed)
{
	int i;

	if (((*data).p >= len_content) &&
			((*data).negatif_int == 1))
		(*data).w--;
	if ((*data).p > len_content)
		i = (*data).w - (*data).p;
	else if ((*data).p <= len_content)
		i = (*data).w - len_content;
	while (((*data).flag != '-') && (((*data).flag != '0') ||
		(((*data).flag == '0') && ((*data).p != -1))) &&
		(--(*data).w >= 0) && ((*data).w >= (*data).p) &&
		((*data).w >= len_content) && ++*printed)
		write(1, " ", 1);
	if ((*data).print_minus == 1)
		write(1, "-", 1);
	while (((*data).flag == '0') && ((*data).p == -1) &&
			(--(*data).w >= 0) &&
			((*data).w >= (*data).p)
			&& ((*data).w >= len_content) && ++*printed)
		write(1, "0", 1);
	return (i);
}

static void		p_c(t_format *data, int len_content, int *printed, int i)
{
	if ((*data).print_minus == 2 && (*data).p++)
		write(1, "-", 1);
	while ((--(*data).p >= 0) &&
			((*data).p >= len_content) && ++*printed)
		write(1, "0", 1);
	if ((*data).print_minus == 1 || (*data).print_minus == 2)
		ft_putstr_fd((*data).content + 1, 1);
	else
		ft_putstr_fd((*data).content, 1);
	if (ft_strncmp((*data).content, "", len_content) != 0)
		*printed += len_content;
	if (((*data).flag == '-') && (i > 0))
		while (i-- && ++*printed)
			write(1, " ", 1);
}

static void		print_int(t_format *data, int len_content, int *printed)
{
	int i;

	i = f_w(data, len_content, printed);
	p_c(data, len_content, printed, i);
}

static void		print_adr(t_format *data, int len_content, int *printed)
{
	len_content += 2;
	if ((*data).w > len_content)
		(*data).w -= len_content;
	else
		(*data).w = 0;
	while (((*data).flag != '-') && (--(*data).w >= 0) &&
			++*printed)
		write(1, " ", 1);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd((*data).content, 1);
	if (((*data).flag == '-') && ((*data).w > 0))
		while ((--(*data).w >= 0) && ++*printed)
			write(1, " ", 1);
	*printed += len_content;
}

void			print_intp(t_format *data, int len_content, int *printed)
{
	if ((*data).cs == 'd' ||
			(*data).cs == 'i' ||
			(*data).cs == 'u' ||
			(*data).cs == 'x' ||
			(*data).cs == 'X')
		print_int(data, len_content, printed);
	else if ((*data).cs == 'p')
		print_adr(data, len_content, printed);
}
