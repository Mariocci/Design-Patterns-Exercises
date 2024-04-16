import Actions.AverageOfNumbers;
import Actions.MedianOfNumbers;
import Actions.SumOfNumbers;
import Actions.WriteFile;
import Sources.FileSource;
import Sources.KeyboardSource;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        NumberSequence sequence = new NumberSequence();
        //sequence.setSource(new FileSource("source.txt"));
        sequence.setSource(new KeyboardSource());
        AverageOfNumbers avg = new AverageOfNumbers();

        sequence.addAction(avg);
        sequence.addAction(new WriteFile());
        sequence.addAction(new SumOfNumbers());
        sequence.addAction(new MedianOfNumbers());

        sequence.begin();

        /*sequence.removeAction(avg);
        sequence.begin();*/
    }
}
