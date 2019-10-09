PriorityQueue: main.o Executive.o PriorityQueue.o
	g++ -g -std=c++11 main.o Executive.o PriorityQueue.o -o PriorityQueue

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -c main.cpp

Executive.o: Executive.h Executive.cpp PriorityQueue.h
	g++ -std=c++11 -g -c Executive.cpp

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp 
	g++ -std=c++11 -g -c PriorityQueue.cpp

clean:
	rm *.o PriorityQueue
