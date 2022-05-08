CXX=g++
CXXFLAGS=-Wall -g -std=c++17
INC_DIRS=blt
INC_PARAM=$(foreach i, $(INC_DIRS), -I$i)
LDLIBS=-lBearLibTerminal

output: main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) main.o -o main $(LDLIBS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INC_PARAM) -c main.cpp

clean:
	rm *.o main
