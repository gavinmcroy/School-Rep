package simulator;

import java.util.Scanner;
import java.util.regex.Pattern;

public class Control {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Pattern p = Pattern.compile(".*:");
        scanner.skip(p);
        int sets = scanner.nextInt();
        scanner.nextLine();
        scanner.skip(p);
        int setSize = scanner.nextInt();
        scanner.nextLine();
        scanner.skip(p);
        int lineSize = scanner.nextInt();
        scanner.nextLine();

        Cache cache = new Cache(sets, setSize, sets * lineSize * setSize,
                lineSize);

        while (scanner.hasNextLine()) {
            String[] str = scanner.nextLine().split(":");
            int memoryAddress;
            if (str[1].contains("0x")) {
                memoryAddress = Integer.decode(str[1]);
            } else {
                memoryAddress = Integer.decode("0x" + str[1]);
            }
            cache.cacheEntry(str[0], memoryAddress, cache.getTag(memoryAddress),
                    cache.getIndex(memoryAddress),
                    cache.getOffset(memoryAddress));
        }
        cache.dumpCache();
    }
}

