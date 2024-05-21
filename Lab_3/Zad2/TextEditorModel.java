import java.util.ArrayList;
import java.util.List;

public class TextEditorModel {
    private List<String> lines;
    private Location cursorLocation;

    public TextEditorModel(String initialText) {
        lines = new ArrayList<>();
        for (String line : initialText.split("\n")) {
            lines.add(line);
        }
        cursorLocation = new Location(0, 0);
    }

    public List<String> getLines() {
        return lines;
    }

    public Location getCursorLocation() {
        return cursorLocation;
    }

    public void moveCursorLeft() {
        if (cursorLocation.getX() > 0) {
            cursorLocation.setX(cursorLocation.getX() - 1);
        }
    }

    public void moveCursorRight() {
        if (cursorLocation.getX() < lines.get(cursorLocation.getY()).length()) {
            cursorLocation.setX(cursorLocation.getX() + 1);
        }
    }

    public void moveCursorUp() {
        if (cursorLocation.getY() > 0) {
            cursorLocation.setY(cursorLocation.getY() - 1);
        }
    }

    public void moveCursorDown() {
        if (cursorLocation.getY() < lines.size() - 1) {
            cursorLocation.setY(cursorLocation.getY() + 1);
        }
    }

    public void deleteBefore() {
    }

    public void deleteAfter() {
    }

    public void insert(char c) {
    }
}
