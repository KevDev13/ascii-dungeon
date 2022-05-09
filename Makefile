EXEC_NAME=dungeon
CXX=g++
CXXFLAGS=-Wall -g -std=c++17
INC_DIRS=ThirdParty
INC_PARAM=$(foreach i, $(INC_DIRS), -I$i)
LDLIBS=-lBearLibTerminal

output: main.o
	$(CXX) $(CXXFLAGS) main.o -o $(EXEC_NAME) $(LDLIBS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INC_PARAM) -c main.cpp

clean:
	rm *.o $(EXEC_NAME)
