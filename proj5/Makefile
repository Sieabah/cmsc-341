FILE=

Proj5.out: Driver.cpp Graph.h Graph.cpp Util.h Exception.h
	g++ -Wall Driver.cpp Graph.cpp -o Proj5.out

compile: 
	g++ -Wall Driver.cpp Graph.cpp -o Proj5.out
	
test: 
	Proj5.out input1.txt < samp
	
run:
	Proj5.out $(FILE)

clean:
	rm Proj5.out
