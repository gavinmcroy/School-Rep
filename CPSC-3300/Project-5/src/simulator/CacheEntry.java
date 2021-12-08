package simulator;

public class CacheEntry {

    private final int address;
    private final int tag;
    private final int index;
    private final int offset;
    private final int memoryReference;
    private final String status;
    private final String type;

    public CacheEntry(String type, int address, int tag, int index, int offset, String status, int memoryReference) {
        this.type = type;
        this.address = address;
        this.tag = tag;
        this.index = index;
        this.offset = offset;
        this.status = status;
        this.memoryReference = memoryReference;
    }

    public String toString() {
        String stringPrint = "";
        String toHexString = Integer.toHexString(address);
        stringPrint = stringPrint + type + "\t   " + toHexString + "\t    " + tag + "\t   " + index + "\t   "
                + offset + "\t   " + status + "\t      " + memoryReference + "\n";
        return stringPrint;
    }

}
