CC := g++

SRC_PATH = .
DIRS = $(shell find $(SRC_PATH) -maxdepth 4 -type d)
#SRC = $(wildcard *.cpp)
SRC = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
OBJ = $(patsubst %.cpp, %.o, $(SRC))

CFLAGS := -I$(PWD)
CFLAGS += -I$(PWD)/exception

TARGET = a.out

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^
	#$(CC) $(CFLAGS) -o $@ $^ -g

.PHONY:clean
clean:
	$(RM) $(OBJ) $(TARGET)

