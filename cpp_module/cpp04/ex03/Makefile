CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3
SRCS =	AMateria.cpp\
		Character.cpp\
		MateriaSource.cpp\
		Cure.cpp\
		Ice.cpp\
		main.cpp
INC =	AMateria.hpp\
		ICharacter.hpp\
		Character.hpp\
		MateriaSource.hpp\
		IMateriaSource.hpp\
		Cure.hpp\
		Ice.hpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex03

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