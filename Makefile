NAME = program

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
INCLUDES_DIR = inc

SRCS =
OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

