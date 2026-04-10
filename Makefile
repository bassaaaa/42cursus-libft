# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/01 19:33:39 by tsito             #+#    #+#              #
#    Updated: 2026/04/10 22:59:15 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft
NAME_A		:=$(NAME).a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CFLAGS		+= -fno-builtin
CPPFLAGS	:= -I.
AR			:= ar
ARFLAGS		:= rcs
RM			:= rm
RMFLAGS		:= -rf

SRCS		:= $(wildcard ft_ctype/*.c) \
			   $(wildcard ft_put_fd/*.c) \
			   $(wildcard ft_stdlib/*.c) \
			   $(wildcard ft_string/*.c)

OUTDIR		:= .out
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME_A)

$(NAME_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A)

re: fclean all

.PHONY: all clean fclean re
