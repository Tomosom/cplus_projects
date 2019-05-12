CC=g++
CFLAGS=-g -Wall -fPIC -c

#SRC = ${wildcard *.cpp}

#out/human:$(SRC)
#	$(CC) $(CFLAGS) -o $@ $^
 
out/human:out/main.o out/libhuman.so
	$(CC) -o $@ $< -Lout/ -lhuman

out/%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ $^

out/libhuman.so:out/Englishman.o out/Chinese.o out/Human.o
	$(CC) -shared -o $@ $^



clean:
	$(RM) out/*

