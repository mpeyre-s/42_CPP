# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 16:27:42 by mathispeyre       #+#    #+#              #
#    Updated: 2025/05/16 13:53:05 by mathispeyre      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project variables
SRCS = main.cpp ScalarConverter.cpp
OBJDIR = objects/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
NAME = convert

# Compiler settings
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

# Colors
ORANGE = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Dynamic project info
PROJECT = cpp06
EXERCISE = ex00
SRC_COUNT = $(words $(SRCS))

all: header $(OBJDIR) $(NAME)

header:
	@echo "\033[38;5;39m—————————————————————————————————————————————————————————\033[0m"
	@echo "\033[38;5;33m|    $(PROJECT)    |    $(EXERCISE)     |    make    |   $(SRC_COUNT) files    |\033[0m"
	@echo "\033[38;5;63m—————————————————————————————————————————————————————————\033[0m"
	@echo "$(ORANGE)Compiling…$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) && \
	echo "" && \
	echo "➡️  $(GREEN)\033[4m./$(NAME)\033[0m$(RESET)$(GREEN) compiled successfully ✅$(RESET)" || \
	echo "$(RED)➡️  Error while compilation$(RESET) ❌" && \
	echo ""

$(OBJDIR)%.o: %.cpp
	@if $(CXX) $(CXXFLAGS) -c $< -o $@; then \
		echo "$(ORANGE)$<$(RESET)	$(GREEN)[OK]$(RESET)"; \
	else \
		echo "$(ORANGE)$<$(RESET)	$(RED)[ERROR]$(RESET)"; \
	fi

clean:
	@$(RM) -r $(OBJDIR)

fclean: clean
	@echo "$(ORANGE)Cleaning files…"
	@echo "*.o		$(RED)[DEL]$(RESET)"
	@for src in $(SRCS); do \
		echo "$(ORANGE)$$src	$(RED)[DEL]$(RESET)"; \
	done
	@$(RM) $(NAME)
	@echo ""
	@echo "$(GREEN)➡️  Project cleaned 🗑️$(RESET)"
	@echo ""

re: fclean all

.PHONY: all clean fclean re header

