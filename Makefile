CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# List of object files
OBJECTS = main.o game.o player.o tile.o vertex.o edge.o card.o

# Main target
all: catan

# Linking the executable
catan: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o catan $(OBJECTS)

# Compiling source files
main.o: main.cpp game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

game.o: game.cpp game.h player.h tile.h
	$(CXX) $(CXXFLAGS) -c game.cpp

player.o: player.cpp player.h card.h
	$(CXX) $(CXXFLAGS) -c player.cpp

tile.o: tile.cpp tile.h vertex.h
	$(CXX) $(CXXFLAGS) -c tile.cpp

vertex.o: vertex.cpp vertex.h edge.h
	$(CXX) $(CXXFLAGS) -c vertex.cpp

edge.o: edge.cpp edge.h
	$(CXX) $(CXXFLAGS) -c edge.cpp

card.o: card.cpp card.h
	$(CXX) $(CXXFLAGS) -c card.cpp

# Clean up object files and executable
clean:
	rm -f *.o catan

