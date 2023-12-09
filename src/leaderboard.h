#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <vector>

// Leaderboard Entry Structure
struct LeaderboardEntry 
{
    int score;

    // Default constructor
    LeaderboardEntry() : score(0) {}

    // Parameterized constructor
    LeaderboardEntry(int s) : score(s) {}

    bool operator < (const LeaderboardEntry& other) const {
        return score > other.score;
    }
};

// Leaderboard Class
class Leaderboard {
public:
    Leaderboard();

    void loadLeaderboard();
    void updateLeaderboard(int newScore);
    void saveLeaderboard();
    void renderLeaderboard();

private:
    std::vector<LeaderboardEntry> leaderboard;
    const std::string fileName;
};

#endif
