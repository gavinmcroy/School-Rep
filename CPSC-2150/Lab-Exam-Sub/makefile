#default: 
#	javac cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/QueueApp.java
#	java cpsc2150.MyQueue.QueueApp
#clean:
#	$(RM) cpsc2150/sets/*.class
##
# source directory

##
SRC_DIR := src


##
# output directory
##
OUT_DIR := cpsc2150/sets

##
# sources
##
SRCS := $(wildcard $(SRC_DIR)/*.java)

##
# classes
## 
CLS := $(SRCS:$(SRC_DIR)/%.java=$(OUT_DIR)/%.class)

##
# compiler and compiler flags
##
JC := javac
JCFLAGS := -d $(OUT_DIR)/ -cp $(SRC_DIR)/

##
# suffixes
##
.SUFFIXES: .java

##
# targets that do not produce output files
##
.PHONY: all clean

##
# default target(s)
##
#all: $(CLS)

#$(CLS): $(OUT_DIR)/%.class: $(SRC_DIR)/%.java
#	$(JC) $(JCFLAGS) $<
all:
	javac cpsc2150/sets/*.java
runInt:
	javac cpsc2150/sets/*.java
	java cpsc2150.sets.SetApp
runDouble: 
	javac cpsc2150/sets/*.java
	java cpsc2150.sets.DoubleSetApp


##
# clean up any output files
##
clean:
	rm $(OUT_DIR)/*.class
