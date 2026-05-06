# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:00:55 by tsito             #+#    #+#              #
#    Updated: 2026/05/06 18:06:50 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft
NAME_A		:= $(NAME).a

CFLAGS		:= -Wall -Wextra -Werror
ARFLAGS		:= rcs

SRCS		:= ft_ctype/ft_isalnum.c \
	ft_ctype/ft_isalpha.c     \
	ft_ctype/ft_isascii.c     \
	ft_ctype/ft_isdigit.c     \
	ft_ctype/ft_isprint.c     \
	ft_ctype/ft_tolower.c     \
	ft_ctype/ft_toupper.c     \
	ft_string/ft_bzero.c      \
	ft_string/ft_memchr.c     \
	ft_string/ft_memcmp.c     \
	ft_string/ft_memcpy.c     \
	ft_string/ft_memmove.c    \
	ft_string/ft_memset.c     \
	ft_string/ft_split.c      \
	ft_string/ft_strchr.c     \
	ft_string/ft_strdup.c     \
	ft_string/ft_striteri.c   \
	ft_string/ft_strjoin.c    \
	ft_string/ft_strlcat.c    \
	ft_string/ft_strlcpy.c    \
	ft_string/ft_strlen.c     \
	ft_string/ft_strmapi.c    \
	ft_string/ft_strncmp.c    \
	ft_string/ft_strnstr.c    \
	ft_string/ft_strrchr.c    \
	ft_string/ft_strtrim.c    \
	ft_string/ft_substr.c     \
	ft_put_fd/ft_putchar_fd.c \
	ft_put_fd/ft_putendl_fd.c \
	ft_put_fd/ft_putnbr_fd.c  \
	ft_put_fd/ft_putstr_fd.c  \
	ft_stdlib/ft_atoi.c       \
	ft_stdlib/ft_calloc.c     \
	ft_stdlib/ft_itoa.c       \
	ft_list/ft_lstadd_back.c  \
	ft_list/ft_lstadd_front.c \
	ft_list/ft_lstclear.c     \
	ft_list/ft_lstdelone.c    \
	ft_list/ft_lstiter.c      \
	ft_list/ft_lstlast.c      \
	ft_list/ft_lstmap.c       \
	ft_list/ft_lstnew.c       \
	ft_list/ft_lstsize.c
INCDIR		:= .
OUTDIR		:= .out
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME_A)

$(NAME_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) -r $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A)

re: fclean all

.PHONY: all clean fclean re
