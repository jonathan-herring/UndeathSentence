CXX = g++
CFLAGS = -Wall -O3
LDFLAGS = -lglut -lGL -lGLU -lm -lstdc++

SRC = src/main.cpp src/game.cpp src/player.cpp src/input.cpp src/zombie.cpp src/bullet.cpp src/ui.cpp src/leaderboard.cpp

all: UndeathSentence

UndeathSentence: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f UndeathSentence
