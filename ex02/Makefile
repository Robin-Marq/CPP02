Name 		:=		a.out
CXX 		:=		c++
CXXFLAGS 	:= 		-Wall -Wextra -Werror -std=c++98
SRC 		:= 		main.cpp Fixed.cpp
OBJS 		:=		$(SRC:.cpp=.o)

$(Name): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(Name)

#Colors
YELLOW	:=	"\033[0;33m"
CYAN	:=	"\033[0;36m"
BLUE	:=	"\033[0;34m"
GREEN	:=	"\033[0;32m"
RED		:=	"\033[0;31m"
RESET	:=	"\033[0m"


all: $(Name)
	@echo $(GREEN) "Compilation of $(Name) is finished and ready" $(RESET)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(Name)
	@clear
	@echo $(YELLOW) "Executable $(Name) and all object files has been successfully removed" $(RESET)

re:	fclean all

.PHONY: all clean fclean re