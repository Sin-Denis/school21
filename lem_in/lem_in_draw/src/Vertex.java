import com.sun.tools.javac.util.Pair;

import java.util.ArrayList;

public class Vertex {
    String name;
    int x;
    int y;
    ArrayList<Integer> adj;

    public Vertex(String name) {
        this.name = name;
        this.adj = new ArrayList<>();
    }

    public Vertex(String name, int x, int y) {
        this(name);
        this.x = x;
        this.y = y;
    }

    public void addEdge(Integer id) {
        this.adj.add(id);
    }
    public int getAdj(int id){
        return(this.adj.get(id));
    }
    public void printAdj(){
        int i;

        i = 0;
        for (Integer node : this.adj)
            System.out.println(this.adj.get(i++));
    }
}
