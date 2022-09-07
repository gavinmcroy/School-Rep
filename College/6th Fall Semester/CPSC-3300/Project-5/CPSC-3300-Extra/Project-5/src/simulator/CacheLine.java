package simulator;

public class CacheLine {

    public int tag;
    public int lastAccess;

    public CacheLine(int tag) {
        this.tag = tag;
    }

    public void increaseLA() {
        lastAccess++;
    }
}
