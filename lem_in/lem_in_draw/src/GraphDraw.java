import javafx.util.Pair;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;

public class GraphDraw extends JComponent {
    private Graph graph;
    private ArrayList<ArrayList<Integer>> waves;
    private ArrayList<Ant> ants;
    private int height;
    private int weight;
    private int stOffset;
    private int waveOffset;

    public GraphDraw(Graph graph) {
        this.graph = graph;
        this.height = 900;
        this.weight = 1500;
        this.stOffset = 100;
        this.waveOffset = 0;
        this.ants = new ArrayList<Ant>();
    }

    public GraphDraw(Graph graph, int height, int weight, int  stOffset) {
        this.graph = graph;
        this.waves = new ArrayList<ArrayList<Integer>>();
        this.height = height;
        this.weight = weight;
        this.stOffset = stOffset;
        this.waveOffset = 0;
        this.ants = new ArrayList<Ant>();
    }

    private void calcWaveOffset(int num_waves) {
        this.waveOffset = (this.weight - 2 * stOffset) / num_waves;
    }

    private void getWaves() {
        this.waves = this.graph.bfs();
    }

    private void evenHandler(ArrayList<Integer> wave, int x) {

    }

    private void oddHandler(ArrayList<Integer> wave, int x) {

    }

    private void setCoordinateItem(int num_wave, ArrayList<Integer> wave) {
        int currX = num_wave == 1 ? stOffset : stOffset + (num_wave - 1) * waveOffset;

        if (wave.size() % 2 == 0) {
            evenHandler(wave, currX);
        } else {
            oddHandler(wave, currX);
        }
    }

    private void setCoordinateStart() {
        Vertex v = this.graph.vertexes.get(this.graph.getStart_idx());
        v.x = 0;
        v.y = this.height / 2;
    }

    private void setCoordinateEnd() {
        Vertex v = this.graph.vertexes.get(this.graph.getEnd_idx());
        v.x = weight;
        v.y = this.height / 2;
    }

    public void setCoordinates() {
        setCoordinateStart();
        setCoordinateEnd();
        getWaves();
        calcWaveOffset(waves.size() - 1);
        for (int i = 1; i < this.waves.size(); ++i) {
            setCoordinateItem(i, waves.get(i));
        }
    }

    public void print() {
        graph.print();
    }

    public void graphDraw() {

    }

    private void antGo(Ant ant, int room_id) {

    }

    public void flowOn(ArrayList<Pair<Integer, Integer>> transitions) {

    }
}
