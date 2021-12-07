package simulator;

import java.util.LinkedList;

public class Cache_Set {

    public int index;
    private final LinkedList<Cache_Line> lines;

    public Cache_Set(int index) {
        this.index = index;
        this.lines = new LinkedList<>();
    }

    public int findLine(int tag) {
        int returnVal = 0;

        for (Cache_Line line : lines) {
            int tempTag = line.tag;
            if (tempTag == tag) {
                //System.out.println("The tags are equal");
                //Its in the cache yay
                returnVal = 1;
                break;
            }
        }
        return returnVal;
    }

    public void addToCache(int tag, int set_size) {

        if (lines.size() == set_size) {
            //We need to replace a line because our set is full
            int tagTemp = lines.get(0).tag;
            int replace = 0;
            for (int i = 0; i < lines.size(); i++) {
                //We need to figure out which line was least recently used
                //The line with highest last access is the least recently used
                if (lines.get(i).tag > tagTemp) {
                    replace = i;
                }
            }
            Cache_Line new_line = new Cache_Line(tag);
            lines.set(replace, new_line);
        } else {
            //The set is not full so we can just add
            Cache_Line new_line = new Cache_Line(tag);
            lines.add(new_line);
        }
    }

    public void increaseLastAccess() {
        for (Cache_Line line : lines) {
            line.increaseLA();
        }
    }

    public void setLAToZero(int tag) {
        for (Cache_Line line : lines) {
            if (line.tag == tag) {
                line.lastAccess = 0;
            }
        }
    }

}
