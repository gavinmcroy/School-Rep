default: simulator/Cache.java simulator/CacheSet.java simulator/CacheEntry.java simulator/CacheLine.java simulator/Control.java
	javac simulator/Cache.java simulator/CacheSet.java simulator/CacheEntry.java simulator/CacheLine.java simulator/Control.java

run: simulator/Cache.class simulator/CacheSet.class simulator/CacheEntry.class simulator/CacheLine.class simulator/Control.class
	java simulator/Control simulator/output.txt

clean:
	rm -f simulator/*.class