OPT = -Wall

assignment01: main.o Calendar.o Event.o Date.o Time.o 
	g++ -o assignment01 main.o  Event.o Date.o Time.o Calendar.o

main.o: main.cc Calendar.h defs.h
	g++ $(OPT) -c main.cc 

Calendar.o: Calendar.cc Calendar.h 
	g++ $(OPT) -c Calendar.cc 

Event.o: Event.cc Event.h
	g++ $(OPT) -c Event.cc 

Date.o: Date.cc Date.h
	g++ $(OPT) -c Date.cc 

Time.o: Time.cc Time.h
	g++ $(OPT) -c Time.cc 

clean:
	rm -f *.o assignment01