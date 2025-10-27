CPP = c++
SANITEER = -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -std=c++98 $(SANITEER)
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = PmergeMe


%.o: %.cpp PmergeMe.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all