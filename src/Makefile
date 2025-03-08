CXX = g++
CXXFLAGS = -ggdb -std=c++20 -Wall -Wextra -Werror -pedantic

# Executables
ladder: ladder.o ladder_main.o
	$(CXX) $(CXXFLAGS) ladder.o ladder_main.o -o ladder

dijkstras: dijkstras.o dijkstras_main.o
	$(CXX) $(CXXFLAGS) dijkstras.o dijkstras_main.o -o dijkstras

# Object files
ladder.o: ladder.cpp ladder.h
	$(CXX) $(CXXFLAGS) -c ladder.cpp -o ladder.o

ladder_main.o: ladder_main.cpp ladder.h
	$(CXX) $(CXXFLAGS) -c ladder_main.cpp -o ladder_main.o

dijkstras.o: dijkstras.cpp dijkstras.h
	$(CXX) $(CXXFLAGS) -c dijkstras.cpp -o dijkstras.o

dijkstras_main.o: dijkstras_main.cpp dijkstras.h
	$(CXX) $(CXXFLAGS) -c dijkstras_main.cpp -o dijkstras_main.o

# Clean object files and executables
clean:
	/bin/rm -f *.o ladder dijkstras
