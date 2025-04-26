CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = prog
SRC = main.cpp Cast.cpp Base.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp Cast.hpp C.hpp A.hpp B.hpp Base.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all