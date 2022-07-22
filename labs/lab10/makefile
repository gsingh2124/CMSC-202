CXX = g++
CXXFLAGS = -Wall

lab10: lab10.cpp Song.o
	$(CXX) $(CXXFLAGS) lab10.cpp Song.o -o lab10

Song.o: Song.h Song.cpp
	$(CXX) $(CXXFLAGS) -c Song.cpp

run:
	./lab10

clean:
	rm *~
