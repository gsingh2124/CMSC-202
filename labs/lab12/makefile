CXX = g++
CXXFLAGS = -Wall -g

lab12: GameCollection.o lab12.cpp
	$(CXX) $(CXXFLAGS) GameCollection.o lab12.cpp -o lab12

GameCollection.o: GameCollection.h GameCollection.cpp
	$(CXX) $(CXXFLAGS) -c GameCollection.cpp

clean:
	rm *.o
	rm *~

run:
	./lab12

val:
	valgrind ./lab12
