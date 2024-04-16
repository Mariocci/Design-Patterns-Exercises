import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class Sheet {

    private final ArrayList<ArrayList<Cell>> cells;

    public Sheet(int rows, int columns) {
        cells = new ArrayList<>();
        for (int i = 0; i < rows; i++) {
            ArrayList<Cell> row = new ArrayList<>();
            for (int j = 0; j < columns; j++) {
                row.add(new Cell(this,Character.toString('A' + j) + (i + 1)));
            }
            cells.add(row);
        }
    }

    public Cell cell(String ref) {
        Map.Entry<Integer, Integer> position = Cell.pozicija(ref);
        return cells.get(position.getKey()).get(position.getValue());
    }

    public Collection<Cell> getRefs(Cell cell) {
        String exp = cell.getExp();
        if (exp == null || exp.matches("\\d+")) {
            return null;
        }
        return Arrays.stream(exp.split("[+]"))
                .map(this::cell)
                .collect(Collectors.toList());
    }
    private void evaluateExp(Cell cell, String exp) {
        if (exp == null || exp.matches("\\d+")) return;

        String[] refs = exp.split("[+]");
        for (String ref : refs) {
            evaluateCellDependency(cell, ref);
        }
    }

    private void evaluateCellDependency(Cell cell, String ref) {
        Cell referencedCell = cell(ref);

        if (referencedCell.isListener(cell) || cell.getName().equals(referencedCell.getName())) {
            throw new RuntimeException("Cycles are not allowed.");
        }

        try {
            evaluateExp(cell, referencedCell.getExp());
            referencedCell.addListener(cell);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    public void set(String ref, String exp) {
        Cell cell = cell(ref);
        Collection<Cell> refsBefore = getRefs(cell);
        if (refsBefore != null) {
            for (Cell r : refsBefore) {
                r.removeListener(cell);
            }
        }

        try {
            evaluateExp(cell, exp);
        } catch (Exception e) {
            if (refsBefore != null) {
                for (Cell r : refsBefore) {
                    r.addListener(cell);
                }
            }
            throw new RuntimeException(e.getMessage());
        }

        cell.setExp(exp);
        evaluate(cell);
    }



    public void evaluate(Cell cell) {
        String exp = cell.getExp();
        Pattern numericPattern = Pattern.compile("\\d+");
        Matcher matcher = numericPattern.matcher(exp);

        if (matcher.matches()) {
            cell.setValue(Integer.parseInt(exp));
            return;
        }

        int value = getRefs(cell)
                .stream()
                .mapToInt(Cell::getValue)
                .sum();

        cell.setValue(value);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (ArrayList<Cell> rowCells : cells) {
            for (Cell cell : rowCells) {
                int value = cell.getValue();
                sb.append(String.format("%5d", value));
            }
            sb.append("\n");
        }
        sb.setLength(sb.length() - 1);
        return sb.toString();
    }


}