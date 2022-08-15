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
		src/ft_char.c \
		src/ft_flags_nbr.c \
		src/ft_flags_str.c \
		src/ft_utils.c \
		src/ft_flags_hex.c \
		src/ft_utils_hex.c \
		src/ft_flags_bonus.c \
		libft/ft_strjoin.c \
		libft/ft_memmove.c \
		libft/ft_itoa.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_calloc.c \
		libft/ft_bzero.c \
		libft/ft_substr.c \
		libft/ft_toupper.c \
		libft/ft_atoi.c

			
SURPL_O = 	ft_evaluate_format.o \
			ft_hex.o \
			ft_numbers.o \
			ft_pointer.o \
			ft_printstr.o \
			ft_unsigned.o \
			ft_flags_nbr.o \
			ft_strjoin.o \
			ft_memmove.o \
			ft_itoa.o \
			ft_strlen.o \
			ft_strdup.o \
			ft_calloc.o \
			ft_bzero.o \
			ft_substr.o \
			ft_flags_str.o \
			ft_char.o \
			ft_utils.o \
			ft_flags_hex.o \
			ft_toupper.o \
			ft_utils_hex.o \
			ft_flags_bonus.o \
			ft_atoi.o
CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./include

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
bonus: $(NAME)

test:
	$(CC) $(SRCS) prueba.c
	
re : fclean all
