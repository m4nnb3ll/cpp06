NAME = convert

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp ConversionInput.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re