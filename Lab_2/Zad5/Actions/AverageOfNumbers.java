package Actions;

import java.util.List;

public class AverageOfNumbers implements Action{
    @Override
    public void update(List<Integer> numbers) {
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        double average = (double) sum / numbers.size();
        System.out.println("Average: " + average);
    }
}
