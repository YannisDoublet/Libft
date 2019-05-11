# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 16:15:49 by yadouble          #+#    #+#              #
#    Updated: 2018/08/14 17:26:09 by yadouble         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJ_DIR = obj
SRCS = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strdel.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strsub.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_is_prime.c \
		ft_find_next_prime.c \
		ft_isblank.c \
		ft_iscntrl.c \
		ft_isupper.c \
		ft_islower.c \
		ft_isxdigit.c \
		ft_uitoa_base.c \
		ft_itoa_base.c \
		ft_strrev.c \
		ft_charinstrcmp.c \
		get_next_line.c \
		ft_printf.c \
		ft_printf/buffer.c \
		ft_printf/format_option.c \
		ft_printf/format_option_2.c \
		ft_printf/format_process.c \
		ft_printf/format_process_2.c \
		ft_printf/get_len.c \
		ft_printf/get_len_2.c \
		ft_printf/parsing.c \
		ft_printf/parsing_step.c \
		ft_printf/process.c \
		ft_printf/process_hexadecimal.c \
		ft_printf/process_int.c \
		ft_printf/process_large_char.c \
		ft_printf/process_octal.c \
		ft_printf/process_strings.c \
		ft_printf/process_unsigned.c
SRCS := $(addprefix $(SRCS_DIR)/,$(SRCS))
OBJ = $(subst $(SRCS_DIR),$(OBJ_DIR),$(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@chmod +x $(NAME)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/ft_printf
	@$(CC) -o $@ -Iincludes $(CFLAGS) $<

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
