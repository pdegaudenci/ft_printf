LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		src/ft_evaluate_format.c \
		src/ft_hex.c \
		src/ft_numbers.c \
		src/ft_pointer.c \
		src/ft_printstr.c \
		src/ft_unsigned.c \
		src/ft_utils.c \
		src/ft_apply_flags.c \
		libft/ft_strjoin.c \
		libft/ft_memmove.c
		
		
SURPL_O = 	ft_evaluate_format.o \
			ft_hex.o \
			ft_numbers.o \
			ft_pointer.o \
			ft_printstr.o \
			ft_unsigned.o \
			ft_utils.o \
			ft_apply_flags.o \
			ft_strjoin.o \
			ft_memmove.o

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
test:
	$(CC) $(FLAGS) $(SRCS)
re : fclean all
