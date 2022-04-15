CXX = clang++
LD = clang++

CXXFLAGS = -std=c++1y -stdlib=libc++ -c -Ofast -g -Wall -Wextra -Werror -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -Ofast -lc++abi

main: main.o graph.o
	$(LD) $(LDFLAGS) -o main main.o graph.o

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

graph.o: graph.cpp 
	$(CXX) $(CXXFLAGS) -c graph.cpp