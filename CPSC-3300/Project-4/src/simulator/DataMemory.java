package simulator;

import java.util.ArrayList;

public class DataMemory {

    private ArrayList<Integer> location = new ArrayList<Integer>();
    private ArrayList<Integer> value = new ArrayList<Integer>();
    private int memoryWrites = 0;
    private int memoryReads = 0;

    public DataMemory(){
        ArrayList<Integer> location = new ArrayList<Integer>();
        ArrayList<Integer> value = new ArrayList<Integer>();
        this.memoryWrites = memoryWrites;
        this.memoryReads = memoryReads;
    }

    public void writeMem(int loc, int val){
        memoryWrites++;
        int addNew = 0;
        for(int i = 0; i < location.size(); i++){
            if(location.get(i) == loc) {
                value.set(i, val);
                addNew = -1;
            }
        }
        if(addNew == 0) {
            location.add(loc);
            value.add(val);
        }
    }

    public int readMem(int loc){

        memoryReads++;

        int length = location.size();
        for(int i = 0; i < length; i++){
            if(location.get(i).equals(loc)){
                return value.get(i);
            }
        }
        return -1;
    }
    public void print(){
        int i;
        for(i = 0; i < location.size(); i++){
            System.out.println(location.get(i) + "\t" + "         :" + value.get(i) + "\n");
        }
    }

    public int getMemoryWrites() {
        return memoryWrites;
    }

    public int getMemoryReads(){
        return memoryReads;
    }

}
