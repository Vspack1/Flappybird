#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

int birdX = WIDTH / 2;
int birdY = HEIGHT / 2;
int score = 0;

int pipeX = WIDTH;
int pipeY = rand() % (HEIGHT - 2) + 1;
int pipeWidth = 2;

bool gameOver = false;

void drawScreen() {
    system("clear"); // clear the screen

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == birdY && j == birdX) {
                cout << "B "; // bird
            } else if (j == pipeX && i >= pipeY && i < pipeY + pipeWidth) {
                cout << "| "; // pipe
            } else {
                cout << "  "; // empty space
            }
        }
        cout << endl;
    }

    cout << "Score: " << score << endl;
}

void update() {
    if (birdY == 0 || birdY == HEIGHT - 1) {
        gameOver = true;
    }

    if (pipeX == birdX && (birdY < pipeY || birdY >= pipeY + pipeWidth)) {
        gameOver = true;
    }

    if (pipeX < 0) {
        pipeX = WIDTH;
        pipeY = rand() % (HEIGHT - 2) + 1;
        score++;
    } else {
        pipeX--;
    }
}

void input() {
    char c;
    cin >> c;

    if (c == ' ') {
        birdY--;
    }
}

int main() {
    srand(time(0)); // seed random number generator

    while (!gameOver) {
        drawScreen();
        input();
        update();
    }

    cout << "Game Over! Your score is " << score << endl;
    return 0;
}