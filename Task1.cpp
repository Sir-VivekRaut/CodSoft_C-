#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // Seed random number generator
    int number = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    std::cout << "Guess the number (between 1 and 100): \n";

    do {
        std::cin >> guess;
        if (guess < number) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > number) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed it right.\n";
        }
    } while (guess != number);

    return 0;
}