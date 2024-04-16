package Actions;

import java.util.List;

public class SumOfNumbers implements Action{
    @Override
    public void update(List<Integer> numbers) {
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        System.out.println("Sum: " + sum);
    }
}
