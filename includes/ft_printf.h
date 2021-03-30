/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:45:16 by obounri           #+#    #+#             */
/*   Updated: 2020/02/27 16:27:39 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_format
{
	int			lf;
	char		cs;
	int			flag;
	int			w;
	int			p;
	int			negatif_int;
	char		*content;
	int			c;
	int			print_minus;
}				t_format;

int				ft_printf(const char *fermat, ...);
int				ft_strlen(const char *str);
int				manage_format(char *str, va_list *arg, int *printed);
int				detect_format(char *str, va_list *arg, t_format *data);
int				ft_atoi(const char *str);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_isdigit(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			output(t_format *data, int *printed, int len_content);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
char			*ft_itoa_hexa(long unsigned int n);
char			*ft_strdup(const char *s1);
void			print_intp(t_format *data, int len_content,
				int *printed);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			print_s(t_format *data, int len_content, int *printed);
void			fill_content(t_format *data, va_list *arg, int *len_content);
char			*ft_strchr(const char *s, int c);

#endif
