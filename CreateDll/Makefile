CXX             = gcc
CXXFLAGS       = --std=c++11 -Wall -g3 -D_REENTERANT -fPIC

TARGET = libmega2.so
OBJECTS = mega2lib.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -shared -o $@ $(OBJECTS)

mega2lib.o: mega2lib.cpp
	$(CXX) $(CXXFLAGS) -c -fPIC $<

clean:
	rm -f $(TARGET) $(OBJECTS)