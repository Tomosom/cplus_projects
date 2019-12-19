include Makefile.param

CC := g++

#SRC_PATH = .
#DIRS = $(shell find $(SRC_PATH) -maxdepth 4 -type d)
#SRC = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
##SRC = $(wildcard *.cpp)

SRC := ./main.cpp
SRC += ./object.cpp
SRC += ./exception/exception.cpp

#OBJ = $(patsubst %.cpp, %.o, $(SRC))
OBJ = $(SRC:%.cpp=%.o)

TARGET = a.out

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

#$(CC) $(CFLAGS) -o $@ $^ -g

.PHONY:clean
clean:
	$(RM) $(OBJ) $(TARGET)

