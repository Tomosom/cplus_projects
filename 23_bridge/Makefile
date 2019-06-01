CC = g++
CFLAGS = -lpthread -Wall

SRC = $(filter-out ${wildcard *_error.cpp}, $(wildcard *.cpp))

OBJS=${patsubst %.cpp, out/%, $(SRC)}


all:$(OBJS)

out/%:%.cpp
	$(CC) -o $@ $^ $(CFLAGS)
    
clean:
	$(RM) out/*

