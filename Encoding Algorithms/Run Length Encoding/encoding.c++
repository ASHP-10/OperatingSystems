#include <iostream>
#include <string>

int main() {
    std::string input, output;

    std::cout << "Enter the Input String: ";
    std::cin >> input;

    int consecutiveN = 0;
    char prev = input[0];

    for (auto i : input) {
        if (i == prev) {
            consecutiveN++;
        } else {
            output += prev + std::to_string(consecutiveN);
            prev = i;
            consecutiveN = 1;
        }
    }

    output += prev + std::to_string(consecutiveN);

    std::cout << "The RLE is " << output << std::endl;

    return 0;
}