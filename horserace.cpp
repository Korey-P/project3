#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TRACK_LENGTH = 15;
const int NUM_HORSES = 5;

void advance(int horses[]) {
    for (int i = 0; i < NUM_HORSES; i++) {
        if (rand() % 2 == 1) {
            horses[i]++;
        }
    }
}

void printRace(int horses[]) {
    for (int i = 0; i < NUM_HORSES; i++) {
        for (int j = 0; j < TRACK_LENGTH; j++) {
            if (j == horses[i]) {
                cout << i;
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

bool checkWinner(int horses[]) {
    for (int i = 0; i < NUM_HORSES; i++) {
        if (horses[i] >= TRACK_LENGTH - 1) {
            cout << "Horse " << i << " WINS!\n";
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(0));
    int horses[NUM_HORSES] = {0};
    bool raceOver = false;

    cout << "Press Enter to start the race...";
    cin.get();

    while (!raceOver) {
        system("clear");

        advance(horses);
        printRace(horses);

        raceOver = checkWinner(horses);

        if (!raceOver) {
            cout << "Press Enter for the next turn...";
            cin.get();
        }
    }

    return 0;
}
