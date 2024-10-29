all: Fs-4

Fs-4: Fs-4.o
	g++ -o Fs-4 Fs-4.o

Fs-4.o: Fs-4.cpp
	g++ -c -Wall Fs-4.cpp

clean:
	rm -f *.o Fs-4
