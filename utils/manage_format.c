/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:48:49 by obounri           #+#    #+#             */
/*   Updated: 2020/02/27 22:41:41 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		catch_exeption(t_format *data, int *len_content)
{
	if (!(*data).content)
		return ;
	if ((ft_strncmp((*data).content, "0", *len_content) == 0) &&
		((*data).p == 0) && ((*data).cs == 'd' || (*data).cs == 'i' ||
		(*data).cs == 'u' || (*data).cs == 'p' || (*data).cs == 'x' ||
		(*data).cs == 'X'))
	{
		*len_content = 0;
		if (((*data).content) && ((*data).cs != 'c'))
			free((*data).content);
		(*data).content = ft_strdup("");
	}
}

int				manage_format(char *str, va_list *arg, int *printed)
{
	t_format	data;
	int			len_content;

	if ((detect_format(str, arg, &data)) == -1)
		return ((data).lf);
	if (!(ft_strchr("cspdiuxX%", (data).cs)))
		return (0);
	fill_content(&data, arg, &len_content);
	if (((data).cs != 'c'))
	{
		if ((data).content[0] == '-')
			(data).negatif_int = 1;
		if ((data).p < -1 || ((data).p >= len_content && (data).cs == 's'))
			(data).p = -1;
		if (((data).p == -1) && ((data).negatif_int == 1))
			(data).print_minus = 1;
		else if (((data).p >= len_content) && ((data).negatif_int == 1))
			(data).print_minus = 2;
	}
	catch_exeption(&data, &len_content);
	output(&data, printed, len_content);
	if (((data).content) && (data.cs != 'c'))
		free((data).content);
	return ((data).lf);
}
