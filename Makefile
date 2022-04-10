CXX = clang++
LD = clang++

CXXFLAGS = -std=c++1y -stdlib=libc++ -c -Ofast -g -Wall -Wextra -Werror -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -Ofast -lc++abi

data_formatter: data_formatter.o
	$(LD) $(LDFLAGS) $^ -o $@

data_formatter.o: src/data_formatter/data_formatter.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@