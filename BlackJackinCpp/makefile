dealcards : Card.o Deck.o dealcards.o
	g++ dealcards.o Card.o Deck.o -o dealcards

dealcards.o : dealcards.cpp Deck.h Card.h
	g++ -Wall -c dealcards.cpp

Deck.o : Deck.cpp Deck.h Card.h
	g++ -Wall -c Deck.cpp

Card.o : Card.cpp Card.h
	g++ -Wall -c Card.cpp

clean:
	rm *.o dealcards
	ls
