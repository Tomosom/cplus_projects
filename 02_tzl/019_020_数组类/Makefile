CC := g++

SRC_PATH = .
DIRS = $(shell find $(SRC_PATH) -maxdepth 3 -type d)
#SRC = $(wildcard *.cpp)
SRC = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
OBJ = $(patsubst %.cpp, %.o, $(SRC))

CFLAGS := -I$(PWD)
CFLAGS += -I$(PWD)/smart_point
CFLAGS += -I$(PWD)/exception
CFLAGS += -I$(PWD)/seq_list
CFLAGS += -I$(PWD)/array

TARGET = a.out

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	$(RM) $(OBJ) $(TARGET)

