CC = g++
EXECUTABLE=test
CFLAGS = -O3 -Istdc++ -Wall -Wextra -Ideps


SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

all: test
test: multi-thread.o 
	$(CC) $(CFLAGS) $^ -lpthread -o $@
	
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)

.PHONY: test  clean install uninstall

