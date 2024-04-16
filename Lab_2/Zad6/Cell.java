import java.util.*;
import java.util.function.Consumer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Cell implements CellObserver {

    private final Sheet sheet;
    private final String name;
    private String exp;
    private int value;

    private final Collection<CellObserver> listeners = new HashSet<>();

    public Cell(Sheet sheet, String name) {
        this.sheet = sheet;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public String getExp() {
        return exp;
    }

    public void setExp(String exp) {
        this.exp = exp;
    }
    public boolean isListener(Cell cell) {
        return cell.listeners.contains(this);
    }

    public void addListener(CellObserver l) {
        listeners.add(l);
    }

    public void removeListener(CellObserver l) {
        listeners.remove(l);
    }

    private void notifyListeners(Consumer<CellObserver> action) {
        listeners.forEach(action);
    }
    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        if (this.value == value) return;
        this.value = value;
        notifyListeners(l -> l.cellUpdated(this));
    }


    @Override
    public String toString() {
        return name;
    }

    @Override
    public void cellUpdated(Cell cell) {
        sheet.evaluate(this);
    }

    public static Map.Entry<Integer, Integer> pozicija(String ref) {
        Optional<Map.Entry<Integer, Integer>> entry = Optional.of(ref.trim())
                .filter(s -> s.length() == 2)
                .map(s -> new AbstractMap.SimpleImmutableEntry<>(
                        Integer.parseInt(s.substring(1)) - 1,
                        s.charAt(0) - 'A'));
        return entry.orElse(null);
    }

}