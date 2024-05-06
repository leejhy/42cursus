CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror# -fsanitize=address -g3
SRCS =	Bureaucrat.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp\
		Intern.cpp\
		Form.cpp\
		main.cpp
INC =	Bureaucrat.hpp\
		ShrubberyCreationForm.hpp\
		RobotomyRequestForm.hpp\
		PresidentialPardonForm.hpp\
		Intern.hpp\
		Form.hpp
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