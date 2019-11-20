CC=g++
CFLAGS= -g -O0

SRC = ${wildcard *.cpp}

SRC = $(filter-out human7_虚函数返回值例外_当前对象指针或引用_error.cpp , $(wildcard *.cpp))

OBJS=${patsubst %.cpp, out/%, $(SRC)}


all:$(OBJS)

out/%:%.cpp
	$(CC) $(CFLAGS) -o $@ $^
    
clean:
	$(RM) $(OBJS) .*.SW?
	$(RM) out/*

