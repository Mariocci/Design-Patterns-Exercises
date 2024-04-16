package Sources;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FileSource implements SourceInterface {
    private BufferedReader reader;

    public FileSource(String filePath) throws IOException {
        reader = new BufferedReader(new FileReader(filePath));
    }

    @Override
    public int read() {
        try {
            String line = reader.readLine();
            if (line != null) {
                return Integer.parseInt(line);
            } else {
                reader.close();
                return -1;
            }
        } catch (IOException e) {
            e.printStackTrace();
            return -1;
        }
    }
}
