FILTER=
DATA=

Proj2.out: Utility.h Utility.cpp Word.h Word.cpp Indexer.h Indexer.cpp
	g++ -Wall Word.cpp Utility.cpp Indexer.cpp Driver.cpp -o Proj2.out

compile:
	g++ -Wall Word.cpp Utility.cpp Indexer.cpp Driver.cpp -o Proj2.out
	
run:
	Proj2.out $(FILTER) $(DATA)

clean:
	rm Proj2.out
	rm filterResults.txt
	rm indexResults.txt
