# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obounri <obounri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 19:42:21 by obounri           #+#    #+#              #
#    Updated: 2020/02/27 15:49:26 by obounri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_SOURCES = srcs/libft/ft_strlen.c \
srcs/libft/ft_atoi.c \
srcs/libft/ft_putnbr_fd.c \
srcs/libft/ft_putchar_fd.c \
srcs/libft/ft_isdigit.c \
srcs/libft/ft_substr.c \
srcs/libft/ft_putstr_fd.c \
srcs/libft/ft_itoa.c \
srcs/libft/ft_strdup.c \
srcs/libft/ft_strncmp.c \
srcs/libft/ft_strchr.c
LIBFT_OBJS = $(LIBFT_SOURCES:.c=.o)
UTILS_SOURCES = utils/manage_format.c \
utils/detect_format.c \
utils/output.c \
utils/ft_itoa_unsigned.c \
utils/ft_itoa_hexa.c \
utils/print_intp.c \
utils/print_s.c \
utils/fill_content.c
UTILS_OBJS = $(UTILS_SOURCES:.c=.o)
SOURCES = ft_printf.c
OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(UTILS_OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(OBJS) $(UTILS_OBJS) $(LIBFT_OBJS)
	@echo "-- Done. --"

clean:
	rm -f $(OBJS) $(LIBFT_OBJS) $(UTILS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
