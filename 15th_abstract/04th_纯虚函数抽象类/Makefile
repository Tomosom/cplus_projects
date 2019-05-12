CC=g++
CFLAGS= -g -O0 -Wall

SRC = ${wildcard *.cpp}

out/human:$(SRC)
	$(CC) $(CFLAGS) -o $@ $^
   
   
clean:
	$(RM) out/*

