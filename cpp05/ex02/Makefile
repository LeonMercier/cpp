# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 13:53:11 by lemercie          #+#    #+#              #
#    Updated: 2025/03/28 16:35:26 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++11

SRCS		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp PresidentialPardonForm.cpp
HEADERS		= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
			  RobotomyRequestForm.hpp PresidentialPardonForm.hpp
OBJS		= $(SRCS:.cpp=.o)
NAME		= test

all: $(NAME) $(HEADERS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *shrubbery

re: fclean all

.PHONY: all, clean, fclean, re
