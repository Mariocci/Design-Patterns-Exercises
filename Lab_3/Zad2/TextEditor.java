import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class TextEditor extends JPanel {
    private TextEditorModel model;
    public TextEditor(TextEditorModel model) {
        this.model = model;
        setPreferredSize(new Dimension(400, 300));
        setFocusable(true);
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_LEFT:
                        model.moveCursorLeft();
                        break;
                    case KeyEvent.VK_RIGHT:
                        model.moveCursorRight();
                        break;
                    case KeyEvent.VK_UP:
                        model.moveCursorUp();
                        break;
                    case KeyEvent.VK_DOWN:
                        model.moveCursorDown();
                        break;
                    case KeyEvent.VK_BACK_SPACE:
                        model.deleteBefore();
                        break;
                    case KeyEvent.VK_DELETE:
                        model.deleteAfter();
                        break;
                    default:
                        char c = e.getKeyChar();
                        if (Character.isDefined(c)) {
                            model.insert(c);
                        }
                }
                repaint();
            }
        });
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        g2d.setColor(Color.BLACK);
        int lineHeight = g2d.getFontMetrics().getHeight();
        int y = lineHeight;
        for (String line : model.getLines()) {
            g2d.drawString(line, 10, y);
            y += lineHeight;
        }

        g2d.setColor(Color.RED);
        Location cursorLocation = model.getCursorLocation();
        g2d.drawLine(10, cursorLocation.getY(), 10, cursorLocation.getY() + lineHeight);
    }

    public static void main(String[] args) {
        String initialText = "Prvi red teksta\nDrugi red teksta";
        TextEditorModel model = new TextEditorModel(initialText);

        TextEditor textEditor = new TextEditor(model);

        JFrame frame = new JFrame("Text Editor");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(textEditor);
        frame.pack();
        frame.setVisible(true);
    }
}

