all: main.o libmega2.so
	g++ -std=c++11 -Wall -g3 -o binary main.o -L. -lmega2 -Wl,-rpath,. -ldl

main.o: main.cpp
	g++ -std=c++11 -Wall -g3 -fPIC -c main.cpp -ldl

install:
	cp ../mega2lib.so ./libmega2lib.so

clean:
	rm -f main.o