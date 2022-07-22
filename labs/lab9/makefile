CXX = g++
CXXFLAGS = -Wall

lab9: Pet.o Dog.o Bird.o lab9.cpp
	$(CXX) $(CXXFLAGS) Pet.o Dog.o Bird.o lab9.cpp -o lab9

Pet.o: Pet.h Pet.cpp
	$(CXX) $(CXXFLAGS) -c Pet.cpp

Dog.o: Pet.o Dog.h Dog.cpp
	$(CXX) $(CXXFLAGS) -c Dog.cpp

Bird.o: Pet.o Bird.h Bird.cpp
	$(CXX) $(CXXFLAGS) -c Bird.cpp

run:
	./lab9
