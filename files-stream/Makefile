CC = g++
EXECUTABLE=test
CFLAGS = -O3 -Istdc++ -Wall -Wextra -Ideps


SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

all: test
test: files-stream.o
	$(CC) $(CFLAGS) $^ -o $@
	
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)

.PHONY: test  clean install uninstall

