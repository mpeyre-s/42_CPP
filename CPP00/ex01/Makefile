# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 16:27:42 by mathispeyre       #+#    #+#              #
#    Updated: 2025/03/06 17:27:07 by mathispeyre      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp

OBJDIR = objects/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
NAME = megaphone
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

ORANGE = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "✅ $(GREEN)./$(NAME) compiled successfully$(RESET)"

$(OBJDIR)%.o: %.cpp
	@echo "🛠️ $(ORANGE) Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "🗑️ $(RED) Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJDIR)

fclean: clean
	@echo "🗑️ $(RED) Cleaning executable...$(RESET)"
	@$(RM) $(NAME)

re: fclean all
