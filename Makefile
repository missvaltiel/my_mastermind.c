CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = my_mastermind

all : $(TARGET)

$(TARGET) : $(OBJ) $(DEPS)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ) 

$(OBJ) : $(SRC) $(DEPS)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all