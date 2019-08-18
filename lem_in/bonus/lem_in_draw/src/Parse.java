import com.sun.xml.internal.ws.api.model.wsdl.WSDLOutput;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Parse {

    private static HashMap<String, Integer> dict;
    private static HashMap<String, Integer> opsToId = new HashMap<String, Integer>();
    private static ArrayList<Pair<Integer, Integer>> transitions = new ArrayList<Pair<Integer, Integer>>();;
    private static int rooms_count;
    private static short toggle;
    private static int num_room = 0;

    private static int add_rooms(Graph g, String str){
       String[] rooms = str.split(" ");
       if (rooms.length != 3)
           return (0);
       dict.put(rooms[0], rooms_count);
       if (toggle == 1){
           g.setStart_idx(rooms_count);
           toggle = 0;
       }
       else if (toggle == 2)
       {
           g.setEnd_idx(rooms_count);
           toggle = 0;
       }
       g.addVert(rooms[0], Integer.parseInt(rooms[1]), Integer.parseInt(rooms[2]));
       rooms_count++;
        return (1);
    }

    private static int add_links(Graph g, String str){

        if (str.startsWith("L"))
            return (0);
        String[] rooms = str.split("-");
        if (rooms.length != 2)
            return (0);
        g.addEdge(dict.get(rooms[0]), dict.get(rooms[1]));
        rooms_count++;
        return (1);
    }

    public static void getAnts(String str){
        String[] ops = str.split(" ");
        for (int i = 0; i < ops.length; ++i){
            String[] opSplit = ops[i].split("-");
            if (!opsToId.containsKey(opSplit[0])) {
                opsToId.put(opSplit[0], num_room);
                transitions.add(new Pair<Integer, Integer>(num_room, dict.get(opSplit[1])));
                ++num_room;
            } else {
                transitions.add(new Pair<Integer, Integer>(opsToId.get(opSplit[0]), dict.get(opSplit[1])));
            }
        }
    }


    public static Graph parse_line() {
        Graph g = new Graph();
        dict = new HashMap<>();
        Scanner scanner = new Scanner(System.in);
        String str;
        while (scanner.hasNextLine()){
            str = scanner.nextLine();
            if (str.contains("##start")){
                toggle = 1;
                continue ;
            } else if (str.contains("##end")){
                toggle = 2;
                continue ;
            }
            else if (str.startsWith("#") || str.startsWith("##"))
                continue ;
            else if (str.isEmpty())
                continue;
            if (str.charAt(0) != '#' && g.getNum_ants() == -1 && str.matches("\\d*"))
                g.setNum_ants(Integer.parseInt(str));
            add_rooms(g, str);
            add_links(g, str);
            if (str.startsWith("L"))
                getAnts(str);
        }
        g.transitions = transitions;
        return g;
    }
}
