# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 13:53:11 by lemercie          #+#    #+#              #
#    Updated: 2025/01/23 17:54:18 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++17

SRCS		= main.cpp Harl.cpp
HEADERS		= Harl.hpp
OBJS		= $(SRCS:.cpp=.o)
NAME		= harlFilter

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
