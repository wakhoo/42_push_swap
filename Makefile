NAME = push_swap
CHECKER = checker
LIBFT = ./libft/libft.a
PUSPLIB = push_swap.a
INCLUDE_DIR = -I ./libft/lib -I ./include/
SRCS_DIR = ./srcs/
SRCS_NAME = \
		free_et_error.c \
		choose_sort.c \
		big_sort.c \
		big_sort_utils.c \
		sort.c \
		find.c \
		set_nodes.c \
		get_nodes.c \
		check_data.c \
		push_bstack.c \
		push_astack.c \
		swap.c \
		reverse.c \
		rereverse.c
BASIC = \
	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
MAIN = ./srcs/main.c
OBJS = $(BASIC:.c=.o)
TOTAL_OBJS = \
	$(BASIC:.c=.o) \
	$(MAIN:.c=.o)
# BNS_FILE = \
# 		./bonus/checker_utils.c	\
# 		./bonus/checker.c
# BNS_OBJS = $(BNS_FILE:.c=.o)
# Options =================================================
CC = cc
# -fsanitize=address
RM = rm -f
CFLAGS = -Werror -Wextra -Wall -g3
# =========================================================

all : $(NAME)

$(NAME): $(TOTAL_OBJS)
	@make -C ./libft	
	@cp ./libft/libft.a $(PUSPLIB)
	@ar -rc $(PUSPLIB) $(TOTAL_OBJS)	
	@$(CC) $(CFLAGS) $(PUSPLIB) -o $(NAME) 
	@$(RM) $(PUSPLIB)

# bonus: $(CHECKER)

# $(CHECKER): $(BNS_OBJS)
# 	@make -C ./libft	
# 	@cp ./libft/libft.a $(PUSPLIB)
# 	@ar -rc $(PUSPLIB) $(OBJS) $(BNS_OBJS)	
# 	@$(CC) $(CFLAGS) $(PUSPLIB) -o $(CHECKER)
# 	@$(RM) $(PUSPLIB)

%.o : %.c
	$(CC) -I ./include/ -c -o $@ $^

clean :
	@make clean -C "./libft" 
	@$(RM) $(TOTAL_OBJS)

fclean : clean
	@make fclean -C "./libft" 
	@$(RM) $(NAME)

re :
	@make fclean
	@make all

.PHONY: all, clean, fclean, re, libmlx