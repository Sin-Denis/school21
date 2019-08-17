import java.awt.*;
import java.awt.image.ImageObserver;
import java.text.AttributedCharacterIterator;
import javax.swing.*;
import java.awt.Graphics;

public class Room extends JComponent {
    private Graph graph;

    public Room(){};
    public Room(Graph graph){
        this.graph = graph;
    }

    public void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D)g;
        for(int i = 0; i < graph.vertexes.size(); i++)
            g2.drawOval(graph.vertexes.get(i).x * 20, graph.vertexes.get(i).y * 20, 20, 20);
    }

}
