CC=g++
CFLAGS= -Wall -g -O0
SRC=${wildcard *.cpp}
OBJS=${patsubst %.cpp, out/%, $(SRC)}

all:$(OBJS)

out/%:%.cpp
	$(CC) $(CFLAGS) -o $@ $^
    
clean:
	$(RM) $(OBJS) .*.SW?


