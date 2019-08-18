import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;

public class Main{

    public static void main(String[] args){
        Graph graph = Parse.parse_line();
        GraphDraw graphDraw = new GraphDraw(graph);
        graphDraw.setCoordinates();
        Window window = new Window("Lem-in", 4096, 2048);
        window.addCloseKey(27);
        window.addGraph(graphDraw.getGraph());
        window.draw();
    }

}
