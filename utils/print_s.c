/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:20:37 by obounri           #+#    #+#             */
/*   Updated: 2020/02/26 20:03:45 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		p_fw(t_format *data, int len_content, int *printed)
{
	if ((*data).w <= len_content && ((*data).p == -1))
		(*data).w = 0;
	else if (((*data).w <= len_content) && ((*data).p != -1))
		(*data).w -= (*data).p;
	else if (((*data).w > len_content) && ((*data).p == -1))
		(*data).w -= len_content;
	else if (((*data).w > len_content) && (*data).p != -1)
		(*data).w -= (*data).p;
	if ((*data).p == -1)
		(*data).p = len_content;
	while (((*data).flag == -1) && (--(*data).w >= 0) && ++*printed)
		write(1, " ", 1);
	while (((*data).flag == '0') && (--(*data).w >= 0) && ++*printed)
		write(1, "0", 1);
}

void			print_s(t_format *data, int len_content, int *printed)
{
	int i;

	p_fw(data, len_content, printed);
	i = 0;
	while ((i < (*data).p) && ++*printed)
		write(1, &(*data).content[i++], 1);
	if (((*data).flag == '-') && ((*data).w > 0))
		while ((--(*data).w >= 0) && ++*printed)
			write(1, " ", 1);
}
