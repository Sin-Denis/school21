import javax.swing.*;
import java.awt.*;

public class Ant_draw extends JComponent {
    int x, y, vel;

    public Ant_draw(int x, int y){
        this.x = x;
        this.y = y;
    }

    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D)g;

        g2.setColor(Color.blue);
        g2.fillOval(x, y, 10, 10);
    }


}
