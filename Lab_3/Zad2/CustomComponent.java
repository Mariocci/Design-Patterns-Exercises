import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CustomComponent extends JComponent {
    public CustomComponent() {
        setPreferredSize(new Dimension(300, 200));

        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    Window window = SwingUtilities.getWindowAncestor(CustomComponent.this);
                    window.dispose();
                }
            }
        });

        setFocusable(true);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        g2d.setColor(Color.RED);
        g2d.drawLine(10, 50, getWidth() - 10, 50);

        g2d.drawLine(50, 10, 50, getHeight() - 10);

        g2d.setColor(Color.BLACK);
        g2d.drawString("Prvi red teksta", 60, 30);
        g2d.drawString("Drugi red teksta", 60, 70);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Custom Component");
            CustomComponent customComponent = new CustomComponent();
            frame.add(customComponent);
            frame.pack();
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
        });
    }
}
