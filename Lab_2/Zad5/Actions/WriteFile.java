package Actions;

import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class WriteFile implements Action{
    public void update(List<Integer> numbers) {
        try (FileWriter writer = new FileWriter("log.txt", true)) {
            SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
            Date date = new Date();
            writer.write("Elements: " + numbers.toString() + " - " + formatter.format(date) + "\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
