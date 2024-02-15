CC:= cc
CFLAGS:= -Wall -Wextra -Werror 
CFLAGS_LINE:= -lreadline

SRC:= ft_parse_manager.c ft_utils_manager.c main.c ft_signal_handler.c
SRC_OUT:= minishell

all: $(SRC_OUT)

$(SRC_OUT):$(SRC)
	$(CC) -o $(SRC_OUT)  $(SRC) $(CFLAGS) $(CFLAGS_LINE) 

