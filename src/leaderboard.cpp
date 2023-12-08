#include "leaderboard.h"
#include <fstream>
#include <algorithm>
#include <GL/glut.h>

Leaderboard::Leaderboard() : fileName("leaderboard.txt") {
    loadLeaderboard();
}

void Leaderboard::loadLeaderboard() {
    std::ifstream file(fileName);
    leaderboard.clear();

    int score;
    while (file >> score) {
        leaderboard.push_back(LeaderboardEntry(score));
    }

    file.close();
}

void Leaderboard::updateLeaderboard(int newScore) {
    leaderboard.push_back(LeaderboardEntry(newScore));
    std::sort(leaderboard.begin(), leaderboard.end());

    const int maxEntries = 5;
    if (leaderboard.size() > maxEntries) {
        leaderboard.resize(maxEntries);
    }
}

void Leaderboard::saveLeaderboard() {
    std::ofstream file(fileName);

    for (const auto& entry : leaderboard) {
        file << entry.score << std::endl;
    }

    file.close();
}

void Leaderboard::renderLeaderboard() {
    float startY = 0.30f;
    float stepY = 0.05f;

    char leaderboardText[20];
    std::sprintf(leaderboardText, "## High Scores ##");

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(0.40, 0.40);

    for (char* c = leaderboardText; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    for (size_t i = 0; i < leaderboard.size(); ++i) {
        char entryText[50];
        std::sprintf(entryText, "%d. %d", static_cast<int>(i + 1), leaderboard[i].score);

        glColor3f(1.0f, 1.0f, 1.0f); // Set text color
        glRasterPos2f(0.40, startY - i * stepY);
        for (char* c = entryText; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }
    }
}
