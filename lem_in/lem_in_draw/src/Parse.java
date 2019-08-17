import com.sun.xml.internal.ws.api.model.wsdl.WSDLOutput;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Parse {

    private static HashMap<String, Integer> dict;
    private static int rooms_count;
    private static short toggle;

    public static int add_rooms(Graph g, String str){
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

    public static int add_links(Graph g, String str){

        if (str.startsWith("L"))
            return (0);
        String[] rooms = str.split("-");
        if (rooms.length != 2)
            return (0);
        g.addEdge(dict.get(rooms[0]), dict.get(rooms[1]));
        rooms_count++;
        return (1);
    }

    public static int getAnts(ArrayList<Ant>ants, String str){

        String[] arr = str.split(" ");
        for (int i = 0; i < arr.length; i++){
            String[] new_str = arr[i].split("-");
            ants.add(new Ant(new_str[0].charAt(1), dict.get(new_str[1])));
        }
        return (0);
    }


    public static Graph parse_line(){
        Graph g = new Graph();
        dict = new HashMap<>();
        ArrayList<Ant>ants = new ArrayList<Ant>();
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
            if (str.charAt(0) != '#' && g.getNum_ants() == -1 && str.matches("\\d*"))
                g.setNum_ants(Integer.parseInt(str));
            add_rooms(g, str);
            add_links(g, str);
            if (str.startsWith("L"))
                getAnts(ants, str);
        }
        for(Ant a : ants){
            System.out.println(a.getId() + " " + a.getRoom_id() + " " );
        }
        return g;
    }





}
