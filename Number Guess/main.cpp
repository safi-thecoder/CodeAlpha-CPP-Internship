#include<iostream>
#include<ctime>
using namespace std;

int main() {
    int guessNum, actualNum;
    
    // Seed the random number generator with the current time
    srand(time(0));
    // Generate a random number between 0 to 999
    actualNum = rand() % 1000;

    // Loop until the user guesses the correct number
    do {
        // Prompt the user to guess the number
        cout << "Guess the Correct Number (0-1000) :: " << endl;
        cin >> guessNum;

        // Check if the guess is correct
        if (guessNum == actualNum) {
            cout << "You guessed the right number!" << endl;
            break;
        }

        // If the guess is lower than the actual number
        if (guessNum < actualNum) {
            int difference = actualNum - guessNum;
            // Provide hints based on the difference between the guess and the actual number
            if (difference >= 500) {
                cout << "You guessed a very low number..." << endl;
            } else if (difference >= 200) {
                cout << "You guessed a low number..." << endl;
            } else if (difference >= 50) {
                cout << "You guessed a little-low number..." << endl;
            } else if (difference >= 15) {
                cout << "You guessed a low number which is very close..." << endl;
            } else if (difference >= 5) {
                cout << "You guessed a low number which is very way-close..." << endl;
            } else {
                cout << "You are just there. (Be higher)..." << endl;
            }
        }

        // If the guess is higher than the actual number
        if (guessNum > actualNum) {
            int difference = guessNum - actualNum;
            // Provide hints based on the difference between the guess and the actual number
            if (difference >= 500) {
                cout << "You guessed a very high number..." << endl;
            } else if (difference >= 200) {
                cout << "You guessed a high number..." << endl;
            } else if (difference >= 50) {
                cout << "You guessed a little-high number..." << endl;
            } else if (difference >= 15) {
                cout << "You guessed a high number which is very close..." << endl;
            } else if (difference >= 5) {
                cout << "You guessed a high number which is very way-close..." << endl;
            } else {
                cout << "You are just there. (Be lower)..." << endl;
            }
        }
    } while (guessNum != actualNum);


    return 0;
}
