# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 03:57:13 by mohtakra          #+#    #+#              #
#    Updated: 2022/11/15 06:07:11 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LIBFTPATH = ./libft_utils/
SRC  = ft_printf.c ft_printf_utils.c \
		$(LIBFTPATH)ft_putchar_fd.c $(LIBFTPATH)ft_strlen.c\
		$(LIBFTPATH)ft_putstr_fd.c $(LIBFTPATH)ft_putnbr_fd.c
OBJ	 = $(SRC:.c=.o)

all: $(NAME)

norm : $(SRC)
	@echo "************************the Norminette result*************************"
	@norminette $(SRC) ft_printf.h

$(NAME): $(OBJ)
		@ar rc $@ $(OBJ)

%.o : %.c ft_printf.h
		@$(CC) -I. -o $@ -c $< $(CFLAGS)
		@echo "the file $@ has been created from $<"

clean:
		@$(RM) $(OBJ) $(OBJB)
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		@echo "the $(NAME) has been deleted"

re: fclean all

.PHONE : clean $(NAME) all fclean re norm