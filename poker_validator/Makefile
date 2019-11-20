pokerValidator: main.o Executive.o Card.o Hand.o
	g++ -std=c++11 -g -Wall main.o Executive.o Card.o Hand.o -o pokerValidator

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Card.o Hand.o
	g++ -std=c++11 -g -Wall -c Executive.cpp

Card.o: Card.h Card.cpp
	g++ -std=c++11 -g -Wall -c Card.cpp

Hand.o: Hand.h Hand.cpp
	g++ -std=c++11 -g -Wall -c Hand.cpp

clean:
	rm *.o pokerValidator