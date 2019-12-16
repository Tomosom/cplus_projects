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

CFLAGS := -I$(PWD)
CFLAGS += -I$(PWD)/smart_point
CFLAGS += -I$(PWD)/exception
CFLAGS += -I$(PWD)/list
CFLAGS += -I$(PWD)/list/seq_list
CFLAGS += -I$(PWD)/array
CFLAGS += -I$(PWD)/list/link_list
CFLAGS += -I$(PWD)/list/dual_link_list
CFLAGS += -I$(PWD)/list/kernel_list

TARGET = a.out

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

#$(CC) $(CFLAGS) -o $@ $^ -g

.PHONY:clean
clean:
	$(RM) $(OBJ) $(TARGET)

