package simulator;

import java.util.LinkedList;

public class Cache {

    private final int sets;
    private final int assoc;
    private final int setSize;
    private final int lineSize;
    private final int offset;
    private final int tag;
    private final int index;
    private final LinkedList<Cache_Set> setList;
    private final LinkedList<Cache_Entry> entryList;
    public int access;
    public int hit;
    public int miss;

    public Cache(int sets, int assoc, int setSize, int lineSize) {
        this.sets = sets;
        this.assoc = assoc;
        this.setSize = setSize;
        this.lineSize = lineSize;
        this.hit = 0;
        this.miss = 0;
        this.access = 0;
        this.setList = new LinkedList<>();
        this.entryList = new LinkedList<>();

        offset = (int) (Math.log(lineSize) / (Math.log(2)));
        index = (int) (Math.log(sets) / Math.log(2));
        tag = 32 - assoc - index;
    }

    public void cacheEntry(String type, int address, int tag, int index, int offset) {
        if (type.equals("R")) {
            type = "read";
        }
        if (type.equals("W")) {
            type = "write";
        }
        //System.out.println("Inside Cache Entry");
        access++;
        int doWeHaveSet = 0;

        //Loop through all sets in the Cache
        int numSets = setList.size();
        int access = 0;
        for (int i = 0; i < numSets; i++) {
            Cache_Set temp_set = setList.get(i);
            if (temp_set.index == index) {
                //We do have this set
                //System.out.println("We do have this in the cache");
                access = i;
                doWeHaveSet = 1;
            }
        }
        //Now let's see if the item is in the set
        if (doWeHaveSet == 1) {
            int returnVal = setList.get(access).findLine(tag);
            setList.get(access).increaseLastAccess();

            if (returnVal == 1) {
                //System.out.println("We have this tag in Cache");
                //We had a cache hit
                //We need to add the cache entry
                int mem = 0;
                String hit_or_miss = "hit";
                //System.out.println("Adding Cache Entry on hit");
                Cache_Entry new_entry = new Cache_Entry(type, address, tag, index, offset, hit_or_miss, mem);
                entryList.add(new_entry);
                setList.get(access).setLAToZero(tag);
                hit++;
            }
            if (returnVal == 0) {
                //System.out.println("We do not have this tag in Cache");
                //We had a cache miss
                //Let's add it to the set

                int mem = 1;
                String hitOrMiss = "miss";
                //System.out.println("Adding Cache Entry on miss");
                Cache_Entry new_entry = new Cache_Entry(type, address, tag, index, offset, hitOrMiss, mem);
                entryList.add(new_entry);
                setList.get(access).addToCache(tag, setSize);
                miss++;
            }
        }
        if (doWeHaveSet == 0) {
            miss++;
            //System.out.println("We do not have this set so we are adding it");
            //We do not have this set, so let's add it
            Cache_Set newSet = new Cache_Set(index);
            setList.add(newSet);
            //Now we need to add the tag to the set
            int most_recent_set = (setList.size() - 1);
            setList.get(most_recent_set).addToCache(tag, setSize);
            //And add to entry
            int mem = 1;
            String hitOrMiss = "miss";
            //System.out.println("Adding Cache Entry on miss");
            Cache_Entry cacheEntry = new Cache_Entry(type, address, tag, index, offset, hitOrMiss, mem);
            entryList.add(cacheEntry);
        }
    }

    public int getTag(int address) {
        address >>>= (offset + index);
        int remainder = Integer.SIZE - tag;
        return (address << remainder) >>> (remainder);
    }

    public int getIndex(int address) {
        address >>>= offset;
        int remainder = Integer.SIZE - index;
        return (address << remainder) >>> (remainder);
    }

    public int getOffset(int address) {
        int remainder = Integer.SIZE - offset;
        return (address << remainder) >>> (remainder);
    }

    public void dumpCache() {
        System.out.println("Cache Configuration\n");
        System.out.print(sets + " ");
        System.out.println(assoc + "-way associative entries of line size\n" + lineSize + " bytes\n");

        System.out.println("Access   Address   Tag   Index   Offset   Status   Memrefs");
        System.out.println("-----------------------------------------------------------");

        StringBuilder cache_entries = new StringBuilder();
        for (Cache_Entry entry : entryList) {
            cache_entries.append(entry.toString());
        }
        System.out.println(cache_entries);
        System.out.println("\nSimulation Summary Statistics");
        System.out.println("-----------------------------");
        System.out.println("Total hits:" + hit);
        System.out.println("Total misses:" + miss);
        System.out.println("Total accesses:" + access);
        System.out.println("Hit Ratio:" + (double) hit / access);
        System.out.println("Miss Ratio:" + (double) miss / access);
    }

}
