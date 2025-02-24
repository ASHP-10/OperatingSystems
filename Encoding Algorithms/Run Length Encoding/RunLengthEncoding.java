import java.util.Scanner;

public class RunLengthEncoding {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the Input String: ");
        String input = scanner.nextLine();
        scanner.close();

        String output = "";
        char prev = input.charAt(0);
        int count = 0;

        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == prev) {
                count++;
            } else {
                output += prev + String.valueOf(count);
                prev = input.charAt(i);
                count = 1;
            }
        }

        output += prev + String.valueOf(count);

        System.out.println("The RLE is: " + output);
    }
}
