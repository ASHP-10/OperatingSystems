import java.util.*;

class Symbol {
    char character;
    int frequency;
    String value;

    public Symbol(char character) {
        this.character = character;
        this.frequency = 1;
        this.value = "";
    }
}

class Table {
    List<Symbol> chars;

    public Table() {
        this.chars = new ArrayList<>();
    }

    public void divideTable(int left, int right) {
        if (left == right) {
            return;
        }

        int totalFrequency = 0;
        for (int i = left; i <= right; ++i) {
            totalFrequency += chars.get(i).frequency;
        }

        int currentSum = 0;
        int mid = left;
        while (mid <= right && currentSum < totalFrequency / 2) {
            currentSum += chars.get(mid).frequency;
            mid++;
        }

        for (int i = left; i < mid; ++i) {
            chars.get(i).value += "0";
        }
        for (int i = mid; i <= right; ++i) {
            chars.get(i).value += "1";
        }

        divideTable(left, mid - 1);
        divideTable(mid, right);
    }
}

public class ShannonFano {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the Input String: ");
        String input = scanner.nextLine();
        scanner.close();

        List<Symbol> symbols = new ArrayList<>();

        for (char c : input.toCharArray()) {
            boolean found = false;
            for (Symbol sym : symbols) {
                if (sym.character == c) {
                    sym.frequency++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                symbols.add(new Symbol(c));
            }
        }

        symbols.sort((a, b) -> Integer.compare(b.frequency, a.frequency));

        Table table = new Table();
        table.chars = symbols;
        table.divideTable(0, table.chars.size() - 1);

        String output = "";
        for (char c : input.toCharArray()) {
            for (Symbol sym : table.chars) {
                if (sym.character == c) {
                    output += sym.value;
                    break;
                }
            }
        }

        System.out.println("The Shannon-Fano encoding is: " + output);
    }
}
