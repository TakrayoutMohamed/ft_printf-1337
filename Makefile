# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 03:57:13 by mohtakra          #+#    #+#              #
#    Updated: 2022/11/14 04:09:56 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC  = ft_printf.c ft_printf_utils.c
OBJ	 = $(SRC:.c=.o)

all: $(NAME)

norm : $(SRC) libprintf.h
	@echo "************************the Norminette result*************************"
	@norminette $(SRC) libprintf.h

$(NAME): $(OBJ)
		
		@ar rc $@ $(OBJ)

%.o : %.c libprintf.h
		@$(CC) -I. -o $@ -c $< $(CFLAGS)
		@echo "the file $@ has been created from $<"

clean:
		@$(RM) $(OBJ) $(OBJB)
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		@echo "the $(NAME) has been deleted"

re: fclean all

.PHONE : clean $(NAME) all fclean re