#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game by Raghav !" << endl;
    cout << "Try to guess the secret number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        }

        attempts++;

    } while (guess != secretNumber);

    return 0;
}
