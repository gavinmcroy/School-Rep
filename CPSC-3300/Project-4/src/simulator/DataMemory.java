package simulator;

import java.util.ArrayList;

public class DataMemory {

    private final ArrayList<Integer> location = new ArrayList<>();
    private final ArrayList<Integer> value = new ArrayList<>();
    private int memoryWrites = 0;
    private int memoryReads = 0;

    public DataMemory() {

    }

    public void writeMem(int location, int val) {
        int addNew = 0;
        for (int i = 0; i < this.location.size(); i++) {
            if (this.location.get(i) != location) {
                continue;
            }
            value.set(i, val);
            addNew = -1;
        }
        if (addNew == 0) {
            this.location.add(location);
            value.add(val);
        }
        memoryWrites++;
    }

    public int readMem(int loc) {
        int length = location.size();
        for (int i = 0; i < length; i++) {
            if (location.get(i).equals(loc)) {
                return value.get(i);
            }
        }
        memoryReads++;
        return -1;
    }

    public void print() {
        for (int i = 0; i < location.size(); i++) {
            System.out.println(location.get(i) + "\t" + "         :" + value.get(i) + "\n");
        }
    }

    public int getMemoryWrites() {
        return memoryWrites;
    }

    public int getMemoryReads() {
        return memoryReads;
    }

}
