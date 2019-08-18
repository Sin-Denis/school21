import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;

public class Main{

    public static void main(String[] args){

        JFrame win = new JFrame("Lem-in");
        win.setSize(1920, 1080);
        win.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Graph g = Parse.parse_line();
        GraphDraw gd = new GraphDraw(g);
        gd.setCoordinates();
        gd.print();
        win.add(g);
        win.setBackground(Color.BLACK);
        win.setLocationRelativeTo(null);
        win.setVisible(true);
    }

}
