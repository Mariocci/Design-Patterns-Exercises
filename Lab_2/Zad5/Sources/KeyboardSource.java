package Sources;

import java.util.Scanner;

public class KeyboardSource implements SourceInterface{
    private Scanner scanner;

    public KeyboardSource() {
        scanner = new Scanner(System.in);
    }

    @Override
    public int read() {
        if (scanner.hasNextInt()) {
            return scanner.nextInt();
        } else {
            return -1;
        }
    }
}
