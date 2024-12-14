CXX=g++
FLAGS=-std=c++20 -g3

all: test

test: main.cpp queue.h
	$(CXX) $(FLAGS) main.cpp -o main

clean:
	rm -f queue.o main