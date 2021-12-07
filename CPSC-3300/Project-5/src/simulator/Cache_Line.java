package simulator;

public class Cache_Line {

    public int tag;
    public int lastAccess;

    public Cache_Line(int tag) {
        this.tag = tag;
    }

    public void increaseLA() {
        lastAccess++;
    }
}
