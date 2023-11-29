CXX = g++
CFLAGS = -Wall -O3
LDFLAGS = -lglut -lGL -lGLU

SRC = src/main.cpp

all: UndeathSentence

UndeathSentence: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f UndeathSentence