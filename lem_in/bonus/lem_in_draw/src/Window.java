import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;

public class Window {
    private JFrame win;
    private BufferedImage img;

    public Window(String title, int width, int height) {
        win = new JFrame(title);
        win.setSize(width, height);
        win.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.img = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        win.setLocationRelativeTo(null);
        win.getContentPane().setBackground(Color.BLACK);
    }

    public void addCloseKey(int keyCode) {
        JLabel close = new JLabel();
        close.setFocusable(true);
        KeyListener k = new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {

            }
            @Override
            public void keyPressed(KeyEvent e) {
                int code;
                code = e.getKeyCode();
                if (code == keyCode) {
                    win.dispose();
                }
            }
            @Override
            public void keyReleased(KeyEvent e) {

            }
        };
        close.addKeyListener(k);
        win.add(close);
    }

    public void addGraph(Graph graph) {
        win.add(graph);
    }

    public void draw() {
        win.setVisible(true);
    }
}
