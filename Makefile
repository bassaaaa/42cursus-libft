# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/01 19:33:39 by tsito             #+#    #+#              #
#    Updated: 2026/04/25 17:27:15 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft
NAME_A		:= $(NAME).a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= rcs
RM			:= rm
RMFLAGS		:= -rf

SRCS		:= $(wildcard *.c)
INCDIR		:= .
OUTDIR		:= .out
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME_A)

$(NAME_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A)

re: fclean all

.PHONY: all clean fclean re
