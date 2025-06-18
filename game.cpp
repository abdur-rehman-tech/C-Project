#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX_TRIES = 6;
    char word[] = "skoudo";
    int wordLength = strlen(word);
    char guessed[26];
    int guessedCount = 0;
    int wrongGuesses = 0;

    char display[20];
    for (int i = 0; i < wordLength; i++) {
        display[i] = '_';
    }
    display[wordLength] = '\0';

    cout << "=== Skoudo Word Game ===" << endl;
    cout << "Guess the word. You have " << MAX_TRIES << " wrong tries.\n" << endl;

    while (wrongGuesses < MAX_TRIES) {
        cout << "Word: ";
        for (int i = 0; i < wordLength; i++) {
            cout << display[i] << " ";
        }
        cout << "\nGuessed letters: ";
        for (int i = 0; i < guessedCount; i++) {
            cout << guessed[i] << " ";
        }

        cout << "\nTries left: " << MAX_TRIES - wrongGuesses;
        cout << "\nEnter a letter: ";
        char guess;
        cin >> guess;

        // check if already guessed
        bool alreadyGuessed = false;
        for (int i = 0; i < guessedCount; i++) {
            if (guessed[i] == guess) {
                alreadyGuessed = true;
                break;
            }
        }

        if (alreadyGuessed) {
            cout << "You already guessed that letter!\n";
            continue;
        }

        guessed[guessedCount] = guess;
        guessedCount++;

        // check if guess is correct
        bool correct = false;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                display[i] = guess;
                correct = true;
            }
        }

        if (correct) {
            cout << "Correct guess!\n";
        } else {
            cout << "Wrong guess.\n";
            wrongGuesses++;
        }

        // check if word is guessed
        bool allGuessed = true;
        for (int i = 0; i < wordLength; i++) {
            if (display[i] == '_') {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "\nCongratulations! You guessed the word: " << word <<endl;
            break;
        }

        cout <<""<<endl;
    }

    if (wrongGuesses == MAX_TRIES) {
        cout << "\nGame Over! The word was: " << word <<endl;
    }

    return 0;
}
