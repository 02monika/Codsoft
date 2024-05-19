#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
    // Initialize random seed
    std::srand(std::time(0));

    // Get the number of digits from the user
    int numDigits;
    std::cout << "Enter the number of digits for the random number: ";
    std::cin >> numDigits;

    // Calculate the range based on the number of digits
    int minNumber = std::pow(10, numDigits - 1);
    int maxNumber = std::pow(10, numDigits) - 1;

    // Generate random number within the range
    int randomNumber = minNumber + std::rand() % (maxNumber - minNumber + 1);
    int guess = 0;

    std::cout << "I have selected a random number with " << numDigits << " digits." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    // Loop until the user guesses the correct number
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Check if the input is a valid number
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(10000, '\n'); // Ignore the invalid input
            std::cout << "Please enter a valid number." << std::endl;
            continue;
        }

        if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
            break;
        }
    }

    return 0;
}
