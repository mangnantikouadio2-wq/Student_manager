CC = gcc
FLAGS = -Wall -Wextra -std=c11
TARGET = manager
SRCS = main.c students.c stats.c loader.c
OBJS = $(SRCS:.c=.o)
HEADER = student.h

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)