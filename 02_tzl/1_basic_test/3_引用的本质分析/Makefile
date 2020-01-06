CC=g++
CFLAGS= -Wall -g -O0
SRC=${wildcard *.cpp}
TARGETS=${patsubst %.cpp, %, $(SRC)}

all:$(TARGETS)

%:%.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(TARGETS) .*.SW?

