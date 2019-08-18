import com.sun.jmx.remote.internal.ArrayQueue;
import com.sun.tools.javac.util.Pair;

import javax.naming.InitialContext;
import javax.swing.*;
import java.awt.*;
import java.util.*;

public class Graph extends JComponent {
   private int	start_idx;
   private int	end_idx;
   private int	num_ants;
   ArrayList<Vertex> vertexes;

   Graph() {
      this.start_idx = -1;
      this.end_idx = -1;
      this.num_ants = -1;
      this.vertexes = new ArrayList<>();
   }

   private Graph(int start_idx) {
      this();
      this.start_idx = start_idx;
   }

   private Graph(int start_idx, int end_idx) {
      this(start_idx);
      this.end_idx = end_idx;
   }

   Graph(int start_idx, int end_idx, int num_ants) {
      this(start_idx, end_idx);
      this.num_ants = num_ants;
   }

   public void addVert(String name, int x, int y) {
      this.vertexes.add(new Vertex(name, x ,y));
   }

   public void addEdge(int id1, int id2) {
      this.vertexes.get(id1).adj.add(id2);
      this.vertexes.get(id2).adj.add(id1);
   }

   public void setNum_ants(int num_ants){
      this.num_ants = num_ants;
   }

   public int getNum_ants(){
      return(num_ants);
   }

   public int getStart_idx(){
      return (start_idx);
   }

   public int getEnd_idx(){
      return (end_idx);
   }

   public void setStart_idx(int start_idx){
      this.start_idx = start_idx;
   }

   public void setEnd_idx(int end_idx){
      this.end_idx = end_idx;
   }

   public Vertex getVertex(int idx) {
      return this.vertexes.get(idx);
   }

   public void print(){
      System.out.println("ANTS : " + this.getNum_ants());
      System.out.println("startId : " + this.getStart_idx() + "endId : " + this.getEnd_idx());
      for (Vertex vertex : this.vertexes){
         System.out.println(vertex.name + " " + vertex.x + " " + vertex.y);
//         vertex.printAdj();
      }
   }

   private void bfsInit() {
      for (Vertex v : this.vertexes) {
         v.frontWave = -1;
      }
      this.vertexes.get(this.start_idx).frontWave = 0;
   }

   public ArrayList<ArrayList<Integer>> bfs() {
      int curr_wave = 0;
      ArrayList<Integer> visited = new ArrayList<Integer>(Collections.nCopies(this.vertexes.size(), 0));
      ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
      ArrayList<ArrayList<Integer>> waves = new ArrayList<ArrayList<Integer>>();
      ArrayList<Integer> wave = new ArrayList<Integer>();

      bfsInit();
      visited.set(end_idx, 2);
      visited.set(this.start_idx, 1);
      queue.addFirst(this.start_idx);
      while(!queue.isEmpty()) {
         int v_idx = queue.removeLast();
         Vertex v = this.vertexes.get(v_idx);
         if (v.frontWave != curr_wave) {
            curr_wave = v.frontWave;
            waves.add((ArrayList<Integer>)wave.clone());
            wave.clear();
         }
         wave.add(v_idx);
         for (Integer u_idx : v.adj) {
            if (visited.get(u_idx) != 0) {
               continue;
            }
            Vertex u = this.vertexes.get(u_idx);
            u.frontWave = v.frontWave + 1;
            visited.set(u_idx, 1);
            queue.addFirst(u_idx);
         }
         visited.set(v_idx, 2);
      }
      if (wave.size() != 0) {
         waves.add(wave);
      }
      return waves;
   }

   public void paintComponent(Graphics g) {
      Graphics2D g2 = (Graphics2D)g;
      ArrayList<Integer> visited = new ArrayList<Integer>(Collections.nCopies(this.vertexes.size(), 0));
      ArrayDeque<Integer> queue = new ArrayDeque<Integer>();

      visited.set(this.start_idx, 1);
      queue.addFirst(this.start_idx);
      g2.setBackground(Color.BLACK);
      g2.setRenderingHints(new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON));
      while(!queue.isEmpty()) {
         int v_idx = queue.removeLast();
         Vertex v = this.vertexes.get(v_idx);
         if (v_idx == this.start_idx || v_idx == this.end_idx)
            g2.setColor(Color.green);
         else
            g2.setColor(Color.blue);
         g2.fillOval(v.x, v.y, 20, 20);
         for (Integer u_idx : v.adj) {
            Vertex u = this.vertexes.get(u_idx);
            g2.setColor(Color.black);
            g2.drawLine(v.x + 10, v.y + 10, u.x + 10, u.y + 10);
            if (visited.get(u_idx) != 0) {
               continue;
            }
            visited.set(u_idx, 1);
            queue.addFirst(u_idx);
         }
         visited.set(v_idx, 2);
      }
   }
}


