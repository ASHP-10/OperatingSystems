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

    // for (auto symbol : symbols) {
    //     std::cout << symbol.frequency;
    // }

    for (int i = 0; i < symbols.size(); ++i) {
        for (int j = symbols.size() - 1; j > i; --j) {
            symbols[i].value += "1";
        }

        if (i != 0) {
            symbols[i].value += "0";
        }
    }

    for (int i = 0; i < input.size(); ++i) {
        for (auto &symbol : symbols) {
            if (symbol.character == input[i]) {
                output += symbol.value;
                break;
            }
        }
    }

    std::cout << "The Huffman Encoding is " << output << std::endl;

    return 0;
}