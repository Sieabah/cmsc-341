FILE=
N=
INTERVAL=
M=
R=

Proj4.out: Driver.cpp QuadraticProbing.h HashTable.h LHashTable.h DHashTable.h
	g++ -Wall Driver.cpp -o Proj4.out

compile:
	g++ -Wall Driver.cpp -o Proj4.out
	
test: 
	Proj4.out hw.txt 28 28 28 7
	
run:
	Proj4.out $(FILE) $(N) $(INTERVAL) $(M) $(R)

clean:
	rm Proj4.out
	rm results.txt
