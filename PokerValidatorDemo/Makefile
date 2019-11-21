poker: main.o Executive.o Hand.o Card.o
	g++ -std=c++11 -g -Wall main.o Executive.o Hand.o Card.o -o poker

main.o: main.cpp Executive.o
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Hand.o: Hand.cpp Hand.h
	g++ -std=c++11 -g -Wall -c Hand.cpp

Card.o: Card.cpp Card.h
	g++ -std=c++11 -g -Wall -c Card.cpp

clean: rm *.o poker