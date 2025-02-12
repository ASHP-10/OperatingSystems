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

class Table {
   public:
    std::vector<Symbol> chars;

   public:
    void divideTable(int left, int right) {
        if (left == right) {
            return;
        }

        int totalFrequency = 0;
        for (int i = left; i <= right; ++i) {
            totalFrequency += chars[i].frequency;
        }

        int currentSum = 0;
        int mid = left;
        while (currentSum < totalFrequency / 2) {
            currentSum += chars[mid].frequency;
            mid++;
        }

        for (int i = left; i < mid; ++i) {
            chars[i].value += "0";
        }
        for (int i = mid; i <= right; ++i) {
            chars[i].value += "1";
        }

        divideTable(left, mid - 1);
        divideTable(mid, right);
    }
};

bool comparator(Symbol &a, Symbol &b) { return a.frequency > b.frequency; }

int main() {
    std::string input;

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

    // for (auto i : symbols) {
    //     std::cout << i.character << " -> " << i.frequency << std::endl;
    // }

    Table table;
    table.chars = symbols;

    table.divideTable(0, table.chars.size() - 1);

    // for (const auto &symbol : table.chars) {
    //     std::cout << symbol.character << " -> " << symbol.value << std::endl;
    // }

    std::string output = "";
    for (int i = 0; i < input.size(); ++i) {
        for (auto &j : table.chars) {
            if (j.character == input[i]) {
                output += j.value;
                break;
            }
        }
    }

    std::cout << "The Shannon fano encoding is: " << output << std::endl;

    return 0;
}