SRC_DIR := src


##
# output directory
##
OUT_DIR := cpsc2150/ExtendedTicTacToe

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
	javac cpsc2150/ExtendedTicTacToe/*.java
run:
	javac cpsc2150/ExtendedTicTacToe/*.java
	java cpsc2150.ExtendedTicTacToe.GameScreen


##
# clean up any output files
##
clean:
	rm $(OUT_DIR)/*.class
