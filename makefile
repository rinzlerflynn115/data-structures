primary: main

main: main.cpp queue.h
	g++ -std=c++20 main.cpp -o main

clean:
	rm -f queue.o main