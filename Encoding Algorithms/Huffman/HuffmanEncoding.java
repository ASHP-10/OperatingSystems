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

public class HuffmanEncoding {
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

        symbols.sort(Comparator.comparingInt(a -> a.frequency));

        for (int i = 0; i < symbols.size(); ++i) {
            for (int j = symbols.size() - 1; j > i; --j) {
                symbols.get(i).value += "1";
            }

            if (i != 0) {
                symbols.get(i).value += "0";
            }
        }

        String output = "";
        for (char c : input.toCharArray()) {
            for (Symbol sym : symbols) {
                if (sym.character == c) {
                    output += sym.value;
                    break;
                }
            }
        }

        System.out.println("The Huffman Encoding is: " + output);
    }
}
