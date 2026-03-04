CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)
