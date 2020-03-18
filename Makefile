all: install main.o libmega2.so
	g++ -std=c++11 -Wall -g3 -o binary main.o -L. -lmega2 -Wl,-rpath,. -ldl

main.o: main.cpp
	g++ -std=c++11 -Wall -g3 -fPIC -c main.cpp -ldl

install:
	cd ./CreateDll && $(MAKE)
	cp CreateDll/libmega2.so ./

clean:
	@$(MAKE) -C CreateDll clean
	rm -f main.o libmega2.so binary