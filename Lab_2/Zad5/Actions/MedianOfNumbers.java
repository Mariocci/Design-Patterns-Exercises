package Actions;

import java.util.Collections;
import java.util.List;

public class MedianOfNumbers implements Action{
    @Override
    public void update(List<Integer> numbers) {
        Collections.sort(numbers);
        int size = numbers.size();
        if (size % 2 == 0) {
            int middle1 = numbers.get(size / 2 - 1);
            int middle2 = numbers.get(size / 2);
            System.out.println("Median: " + (middle1 + middle2) / 2.0);
        } else {
            System.out.println("Median: " + numbers.get(size / 2));
        }
    }
}
