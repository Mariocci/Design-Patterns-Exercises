import Actions.Action;
import Sources.SourceInterface;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class NumberSequence {
    private final ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);
    private SourceInterface source;
    private List<Action> actions = new ArrayList<Action>();
    private List<Integer> numbers = new ArrayList<Integer>();

    public void setSource(SourceInterface source) {
        this.source = source;
    }
    public void begin() {
        scheduler.scheduleAtFixedRate(this::readNextNumber, 0, 1, TimeUnit.SECONDS);
    }
    public void addAction(Action action){
        actions.add(action);
    }
    public void removeAction(Action action){
        actions.remove(action);
    }
    public void actionNotify(){
        for (Action action : actions){
            action.update(numbers);
        }
    }

    private void readNextNumber() {
        int nextNumber = source.read();
        if (nextNumber != -1) {
            numbers.add(nextNumber);
            actionNotify();
        } else {
            scheduler.shutdown();
        }
    }
}
