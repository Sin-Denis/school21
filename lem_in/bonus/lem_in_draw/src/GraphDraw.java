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
    private int height;
    private int weight;
    private int left;
    private int top;
    private int stOffset;
    private int waveOffset;

    public GraphDraw(Graph graph) {
        this.graph = graph;
        this.height = 1180;
        this.weight = 2300;
        this.stOffset = 100;
        this.waveOffset = 0;
        this.left = 100;
        this.top = 100;
    }

    public GraphDraw(Graph graph, int height, int weight, int  stOffset) {
        this.graph = graph;
        this.waves = new ArrayList<ArrayList<Integer>>();
        this.height = height;
        this.weight = weight;
        this.stOffset = stOffset;
        this.waveOffset = 0;
        this.left = 100;
        this.top = 100;
    }

    private void calcWaveOffset(int num_waves) {
        this.waveOffset = (this.weight - 2 * stOffset) / num_waves;
    }

    private void getWaves() {
        this.waves = this.graph.bfs();
    }

    private void evenHandler(ArrayList<Integer> wave, int x) {
        int beginY = 0;
        int step = this.height / (wave.size() - 1);
        for (int i = 0; i < wave.size(); ++i) {
            Vertex v = this.graph.getVertex(wave.get(i));
            v.x = left + x;
            v.y = top + beginY + i * step;
        }
    }

    private void oddHandler(ArrayList<Integer> wave, int x) {
        int step = this.height / wave.size();
        int beginY = this.height / (2 * wave.size());
        for (int i = 0; i < wave.size(); ++i) {
            Vertex v = this.graph.getVertex(wave.get(i));
            v.x = left + x;
            v.y = top + beginY + i * step;
        }
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
        v.x = left;
        v.y = top + this.height / 2;
    }

    private void setCoordinateEnd() {
        Vertex v = this.graph.vertexes.get(this.graph.getEnd_idx());
        v.x = left + weight;
        v.y = top + this.height / 2;
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

    public Graph getGraph() {
        return this.graph;
    }

    public void print() {
        graph.print();
    }

    private void put_ants(){

    }
    private void antGo(Pair<Integer, Integer> ant, int room_id) {
        Vertex destVert = graph.getVertex(room_id);
        Vertex srcVert = graph.getVertex(ant.getValue());
    }

    public void flowOn() {

    }
}
