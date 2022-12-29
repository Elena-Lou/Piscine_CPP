SRCS = Account.cpp \
		tests.cpp 

CPPFLAGS = -MMD -MF $(@:.o=.d)

INC = ./

NAME = account

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS_DIR = ./objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

DEPS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.d))

all: $(NAME)
	@make $(NAME) -q && echo "All good here !"

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(CPPFLAGS) -I $(INC)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean
	@make all

-include $(DEPS)

.PHONY: all clean fclean re
	