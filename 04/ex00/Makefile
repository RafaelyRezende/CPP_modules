CCXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS=Animal.cpp Cat.cpp Dog.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)

NAME=poly

all: $(NAME)

$(NAME): $(OBJS)
	$(CCXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CCXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re