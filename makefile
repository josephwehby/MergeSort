CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror

SRC = src/merge_Sort.cpp
EXEC = mergesort

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -rf $(EXEC)


