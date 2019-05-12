CC=g++
CFLAGS= -g -O0

SRC = ${wildcard *.cpp}

out/human:$(SRC)
	$(CC) $(CFLAGS) -o $@ $^
   
   
clean:
	$(RM) out/*

