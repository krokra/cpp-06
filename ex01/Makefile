C++ := c++ -std=c++98
RM := rm -rf
NAME := program
SRCS := main.cpp \
		Serializer.cpp
SRC := $(addprefix $(SRC_DIR), $(SRCS))
OBJ := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	${C++} $^ -g -o ${NAME}

%.o: %.cpp
	${C++} -c $? -g -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHOMY: all clean fclean re 