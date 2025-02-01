#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TRACK_LENGTH = 15;  // Length of the race track
const int NUM_HORSES = 5;     // Number of horses

// Move horses based on a coin flip
void advance(int horses[]) {
    for (int i = 0; i < NUM_HORSES; i++) {
        int coin = rand() % 2;  // Flip a coin (0 or 1)
        if (coin == 1) {
            horses[i]++;  // Move horse forward if 1
        }
    }
}

// Print the current race track
void printRace(int horses[]) {
    for (int i = 0; i < NUM_HORSES; i++) {
        for (int j = 0; j < TRACK_LENGTH; j++) {
            if (j == horses[i]) {
                cout << i;  // Display horse number at position
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

// Check if any horse has won
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
    srand(time(0));  // Random number generator
    int horses[NUM_HORSES] = {0};  // horse positions
    bool raceOver = false;

    cin.get();  

    while (!raceOver) {
        system("clear");  

        advance(horses);   // Move horse based on flip
        printRace(horses); // Display race track

        raceOver = checkWinner(horses);  // Check if horse won

        if (!raceOver) {
            cin.get(); 
        }
    }

    return 0;
}
