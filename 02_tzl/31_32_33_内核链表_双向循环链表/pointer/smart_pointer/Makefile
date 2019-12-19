include ../../Makefile.param

CC := g++

SRC += ./main.cpp

all:
	echo $(SRC)

OBJ = $(SRC:%.cpp=%.o)

TARGET = a.out

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	$(RM) $(OBJ) $(TARGET)

