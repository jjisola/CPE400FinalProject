# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++11
OBJECTS = main.o Graph.o

# Target
all: main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $(OBJECTS)

main.o: main.cpp Graph.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Graph.o: Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) -c Graph.cpp

clean:
	rm -f *.o main