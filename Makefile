CC=g++ -std=c++0x
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=./src/main.cpp ./src/table.cpp ./src/Etudiant.cpp ./src/PerfTest.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=executable

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


