CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror

SRC = src/merge_Sort.cpp
EXEC = bin/mergesort

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

run_scripts: $(EXEC)
	./mergesort.sh 5 output1
	./mergesort.sh 10 output2
	./mergesort.sh 15 output3
	./mergesort.sh 17 output4
	./mergesort.sh 20 output5

clean:
	rm -rf $(EXEC)


