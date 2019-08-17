public class Ant {
    private int id;
    private int room_id;
    private int color;

    public Ant(){};
    public Ant(int id){
        this.id = id;
    }

    public Ant(int id, int room_id){
        this(id);
        this.room_id = room_id;
    }

    public Ant(int id, int room_id, int color){
        this(id, room_id);
        this.color = color;
    }

    public int getId(){
        return(this.id);
    }

    public int getRoom_id(){
        return(this.room_id);
    }

    public int getColor(){
        return(this.color);
    }
}
