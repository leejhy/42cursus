CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror# -fsanitize=address -g3
SRCS =	Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		Brain.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp\
		main.cpp
INC =	Animal.hpp\
		Dog.hpp\
		Cat.hpp\
		Brain.hpp\
		WrongAnimal.hpp\
		WrongCat.hpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex01

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp $(INC)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all