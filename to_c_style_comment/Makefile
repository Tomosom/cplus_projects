CC=gcc
CFLAGS= -g -O0

SRC = to_c_style_comment.c

TARGET = ${patsubst %.c, %, $(SRC)}


all:$(TARGET)

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^
    
clean:
	$(RM) $(TARGET) .*.SW?

