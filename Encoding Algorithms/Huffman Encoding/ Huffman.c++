#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Symbol {
   public:
    char character;
    int frequency = 0;
    std::string value;

    Symbol(char character) : character(character), frequency(1), value("") {}
};

bool comparator(Symbol &a, Symbol &b) { return a.frequency < b.frequency; }

int main() {
    std::string input, output;

    std::cout << "Enter the Input String: ";
    std::cin >> input;

    std::vector<Symbol> symbols;

    for (char i : input) {
        bool found = false;

        for (auto &sym : symbols) {
            if (sym.character == i) {
                sym.frequency++;
                found = true;
                break;
            }
        }

        if (!found) {
            symbols.push_back(Symbol(i));
        }
    }

    std::sort(symbols.begin(), symbols.end(), comparator);

        return 0;
}